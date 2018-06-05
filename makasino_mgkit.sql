-- phpMyAdmin SQL Dump
-- version 4.7.3
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Янв 17 2018 г., 16:44
-- Версия сервера: 5.6.38
-- Версия PHP: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `makasino_mgkit`
--
CREATE DATABASE IF NOT EXISTS `makasino_mgkit` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `makasino_mgkit`;

-- --------------------------------------------------------

--
-- Структура таблицы `Charity`
--

DROP TABLE IF EXISTS `Charity`;
CREATE TABLE `Charity` (
  `CharityId` int(11) NOT NULL,
  `CharityName` varchar(100) NOT NULL,
  `CharityDescription` text NOT NULL,
  `CharityLogo` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Country`
--

DROP TABLE IF EXISTS `Country`;
CREATE TABLE `Country` (
  `CountryCode` varchar(3) NOT NULL,
  `CountryName` varchar(15) NOT NULL,
  `CountryFlag` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Event`
--

DROP TABLE IF EXISTS `Event`;
CREATE TABLE `Event` (
  `EventId` int(11) NOT NULL,
  `EventName` varchar(100) NOT NULL,
  `EventTypeId` int(11) NOT NULL,
  `MarathonId` int(11) NOT NULL,
  `StartDateTime` date NOT NULL,
  `Cost` int(11) NOT NULL,
  `MaxParticipants` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `EventType`
--

DROP TABLE IF EXISTS `EventType`;
CREATE TABLE `EventType` (
  `EventTypeId` int(11) NOT NULL,
  `EventTypeName` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Gender`
--

DROP TABLE IF EXISTS `Gender`;
CREATE TABLE `Gender` (
  `Gender` varchar(1) NOT NULL COMMENT 'Male/Female'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `Gender`
--

INSERT INTO `Gender` (`Gender`) VALUES
('F'),
('M');

-- --------------------------------------------------------

--
-- Структура таблицы `Marathon`
--

DROP TABLE IF EXISTS `Marathon`;
CREATE TABLE `Marathon` (
  `MarathonId` int(11) NOT NULL,
  `MarathonName` varchar(100) NOT NULL,
  `CityName` varchar(50) NOT NULL,
  `CountryCode` varchar(3) NOT NULL,
  `YearHeld` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Position`
--

DROP TABLE IF EXISTS `Position`;
CREATE TABLE `Position` (
  `PositionId` int(11) NOT NULL,
  `PositionName` varchar(50) NOT NULL,
  `PositionDescription` varchar(100) NOT NULL,
  `PayPeriod` varchar(100) NOT NULL,
  `PayRate` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `RaceKitOption`
--

DROP TABLE IF EXISTS `RaceKitOption`;
CREATE TABLE `RaceKitOption` (
  `RaceKitOptionId` int(11) NOT NULL,
  `RaceKitOption` varchar(100) NOT NULL,
  `Cost` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Registration`
--

DROP TABLE IF EXISTS `Registration`;
CREATE TABLE `Registration` (
  `RegistrationId` int(11) NOT NULL,
  `RunnerId` int(11) NOT NULL,
  `RegistrationDateTime` int(11) NOT NULL,
  `RaceKitOptionId` int(11) NOT NULL,
  `RegistrationStatusId` int(11) NOT NULL,
  `Cost` int(11) NOT NULL,
  `CharityId` int(11) NOT NULL,
  `SponsorshipTarget` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `RegistrationStatus`
--

DROP TABLE IF EXISTS `RegistrationStatus`;
CREATE TABLE `RegistrationStatus` (
  `RegistrationStatusId` int(11) NOT NULL,
  `RegistrationStatus` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Registration_Event`
--

DROP TABLE IF EXISTS `Registration_Event`;
CREATE TABLE `Registration_Event` (
  `Registration_EventId` int(11) NOT NULL,
  `RegistrationId` int(11) NOT NULL,
  `EventId` int(11) NOT NULL,
  `BibNumber` tinyint(4) NOT NULL,
  `RaceTime` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Role`
--

DROP TABLE IF EXISTS `Role`;
CREATE TABLE `Role` (
  `RoleId` tinyint(1) NOT NULL DEFAULT '1' COMMENT '1-USER; 2-RUNNER; 3-COORDINATOR; 4-ADMIN',
  `RoleName` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `Role`
--

INSERT INTO `Role` (`RoleId`, `RoleName`) VALUES
(1, 'user'),
(2, 'runner'),
(3, 'coordinator'),
(4, 'admin');

-- --------------------------------------------------------

--
-- Структура таблицы `Runner`
--

DROP TABLE IF EXISTS `Runner`;
CREATE TABLE `Runner` (
  `RunnerId` int(11) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Gender` varchar(1) NOT NULL,
  `DateOfBirth` date NOT NULL,
  `CountryCode` varchar(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Sponsorship`
--

DROP TABLE IF EXISTS `Sponsorship`;
CREATE TABLE `Sponsorship` (
  `SponsorshipId` int(11) NOT NULL,
  `SponsorshipName` varchar(100) NOT NULL,
  `RegistrationId` int(11) NOT NULL,
  `Amount` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Staff`
--

DROP TABLE IF EXISTS `Staff`;
CREATE TABLE `Staff` (
  `StaffId` int(11) NOT NULL,
  `FirstName` int(11) NOT NULL,
  `LastName` int(11) NOT NULL,
  `DateOfBitrh` date NOT NULL,
  `Gender` varchar(1) NOT NULL COMMENT 'M/F (Male/Female)',
  `PositionId` int(11) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Comments` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Timesheet`
--

DROP TABLE IF EXISTS `Timesheet`;
CREATE TABLE `Timesheet` (
  `TimesheetId` int(11) NOT NULL,
  `StaffId` int(11) NOT NULL,
  `StartDateTime` varchar(50) NOT NULL COMMENT '50',
  `EndDateTime` varchar(50) NOT NULL COMMENT '50',
  `PayAmount` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `User`
--

DROP TABLE IF EXISTS `User`;
CREATE TABLE `User` (
  `Email` varchar(50) NOT NULL,
  `Password` varchar(50) NOT NULL,
  `FirstName` varchar(50) NOT NULL,
  `LastName` varchar(50) NOT NULL,
  `RoleId` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Структура таблицы `Users`
--

DROP TABLE IF EXISTS `Users`;
CREATE TABLE `Users` (
  `Email` varchar(35) NOT NULL,
  `Password` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `Users`
--

INSERT INTO `Users` (`Email`, `Password`) VALUES
('login', 'password');

-- --------------------------------------------------------

--
-- Структура таблицы `Volunteer`
--

DROP TABLE IF EXISTS `Volunteer`;
CREATE TABLE `Volunteer` (
  `VolunteerId` int(11) NOT NULL,
  `FirstName` varchar(50) NOT NULL,
  `LastName` varchar(50) NOT NULL,
  `CountryCode` varchar(3) NOT NULL,
  `Gender` varchar(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `Charity`
--
ALTER TABLE `Charity`
  ADD PRIMARY KEY (`CharityId`);

--
-- Индексы таблицы `Country`
--
ALTER TABLE `Country`
  ADD PRIMARY KEY (`CountryCode`);

--
-- Индексы таблицы `Event`
--
ALTER TABLE `Event`
  ADD PRIMARY KEY (`EventId`),
  ADD UNIQUE KEY `MarathonId` (`MarathonId`),
  ADD UNIQUE KEY `EventTypeId` (`EventTypeId`);

--
-- Индексы таблицы `EventType`
--
ALTER TABLE `EventType`
  ADD PRIMARY KEY (`EventTypeId`);

--
-- Индексы таблицы `Gender`
--
ALTER TABLE `Gender`
  ADD PRIMARY KEY (`Gender`),
  ADD UNIQUE KEY `Gender` (`Gender`);

--
-- Индексы таблицы `Marathon`
--
ALTER TABLE `Marathon`
  ADD PRIMARY KEY (`MarathonId`),
  ADD UNIQUE KEY `CountryCode` (`CountryCode`),
  ADD UNIQUE KEY `CountryCode_3` (`CountryCode`),
  ADD KEY `CountryCode_2` (`CountryCode`);

--
-- Индексы таблицы `Position`
--
ALTER TABLE `Position`
  ADD PRIMARY KEY (`PositionId`);

--
-- Индексы таблицы `RaceKitOption`
--
ALTER TABLE `RaceKitOption`
  ADD PRIMARY KEY (`RaceKitOptionId`);

--
-- Индексы таблицы `Registration`
--
ALTER TABLE `Registration`
  ADD PRIMARY KEY (`RegistrationId`),
  ADD UNIQUE KEY `RunnerId` (`RunnerId`),
  ADD UNIQUE KEY `RaceKitOptionId` (`RaceKitOptionId`),
  ADD UNIQUE KEY `RegistrationStatusId` (`RegistrationStatusId`),
  ADD UNIQUE KEY `CharityId` (`CharityId`);

--
-- Индексы таблицы `RegistrationStatus`
--
ALTER TABLE `RegistrationStatus`
  ADD PRIMARY KEY (`RegistrationStatusId`);

--
-- Индексы таблицы `Registration_Event`
--
ALTER TABLE `Registration_Event`
  ADD PRIMARY KEY (`Registration_EventId`),
  ADD UNIQUE KEY `EventId` (`EventId`),
  ADD UNIQUE KEY `RegistrationId` (`RegistrationId`);

--
-- Индексы таблицы `Role`
--
ALTER TABLE `Role`
  ADD PRIMARY KEY (`RoleId`);

--
-- Индексы таблицы `Runner`
--
ALTER TABLE `Runner`
  ADD PRIMARY KEY (`RunnerId`),
  ADD UNIQUE KEY `Gender` (`Gender`),
  ADD UNIQUE KEY `Email` (`Email`),
  ADD KEY `CountryCode` (`CountryCode`);

--
-- Индексы таблицы `Sponsorship`
--
ALTER TABLE `Sponsorship`
  ADD PRIMARY KEY (`SponsorshipId`),
  ADD UNIQUE KEY `RegistrationId` (`RegistrationId`);

--
-- Индексы таблицы `Staff`
--
ALTER TABLE `Staff`
  ADD PRIMARY KEY (`StaffId`),
  ADD UNIQUE KEY `PositionId` (`PositionId`);

--
-- Индексы таблицы `Timesheet`
--
ALTER TABLE `Timesheet`
  ADD PRIMARY KEY (`TimesheetId`),
  ADD UNIQUE KEY `StaffId` (`StaffId`);

--
-- Индексы таблицы `User`
--
ALTER TABLE `User`
  ADD PRIMARY KEY (`Email`),
  ADD UNIQUE KEY `RoleId` (`RoleId`);

--
-- Индексы таблицы `Volunteer`
--
ALTER TABLE `Volunteer`
  ADD PRIMARY KEY (`VolunteerId`),
  ADD UNIQUE KEY `Gender` (`Gender`),
  ADD UNIQUE KEY `CountryCode` (`CountryCode`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `Runner`
--
ALTER TABLE `Runner`
  MODIFY `RunnerId` int(11) NOT NULL AUTO_INCREMENT;
--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `Event`
--
ALTER TABLE `Event`
  ADD CONSTRAINT `Event_ibfk_1` FOREIGN KEY (`EventTypeId`) REFERENCES `EventType` (`EventTypeId`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Event_ibfk_2` FOREIGN KEY (`MarathonId`) REFERENCES `Marathon` (`MarathonId`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Event_ibfk_3` FOREIGN KEY (`EventId`) REFERENCES `Registration_Event` (`EventId`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Marathon`
--
ALTER TABLE `Marathon`
  ADD CONSTRAINT `Marathon_ibfk_1` FOREIGN KEY (`CountryCode`) REFERENCES `Country` (`CountryCode`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Registration`
--
ALTER TABLE `Registration`
  ADD CONSTRAINT `Registration_ibfk_1` FOREIGN KEY (`RegistrationId`) REFERENCES `Sponsorship` (`RegistrationId`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Registration_ibfk_2` FOREIGN KEY (`CharityId`) REFERENCES `Charity` (`CharityId`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Registration_ibfk_3` FOREIGN KEY (`RegistrationStatusId`) REFERENCES `RegistrationStatus` (`RegistrationStatusId`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Registration_ibfk_4` FOREIGN KEY (`RaceKitOptionId`) REFERENCES `RaceKitOption` (`RaceKitOptionId`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Registration_Event`
--
ALTER TABLE `Registration_Event`
  ADD CONSTRAINT `Registration_Event_ibfk_1` FOREIGN KEY (`RegistrationId`) REFERENCES `Registration` (`RegistrationId`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Runner`
--
ALTER TABLE `Runner`
  ADD CONSTRAINT `Runner_ibfk_1` FOREIGN KEY (`Email`) REFERENCES `User` (`Email`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Runner_ibfk_3` FOREIGN KEY (`CountryCode`) REFERENCES `Country` (`CountryCode`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Runner_ibfk_4` FOREIGN KEY (`RunnerId`) REFERENCES `Registration` (`RunnerId`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Runner_ibfk_5` FOREIGN KEY (`Gender`) REFERENCES `Gender` (`Gender`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Staff`
--
ALTER TABLE `Staff`
  ADD CONSTRAINT `Staff_ibfk_1` FOREIGN KEY (`PositionId`) REFERENCES `Position` (`PositionId`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Timesheet`
--
ALTER TABLE `Timesheet`
  ADD CONSTRAINT `Timesheet_ibfk_1` FOREIGN KEY (`StaffId`) REFERENCES `Staff` (`StaffId`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `User`
--
ALTER TABLE `User`
  ADD CONSTRAINT `User_ibfk_1` FOREIGN KEY (`RoleId`) REFERENCES `Role` (`RoleId`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `Volunteer`
--
ALTER TABLE `Volunteer`
  ADD CONSTRAINT `Volunteer_ibfk_1` FOREIGN KEY (`Gender`) REFERENCES `Gender` (`Gender`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Volunteer_ibfk_2` FOREIGN KEY (`CountryCode`) REFERENCES `Country` (`CountryCode`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
