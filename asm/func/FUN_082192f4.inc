	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x70
	adds r0, r0, r6
	mov sb, r0
	ldr r1, _08219388 @ =0x000012C8
	adds r7, r6, r1
	movs r2, #1
	mov r8, r2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	mov r3, r8
	ands r1, r3
	cmp r1, #0
	beq _0821931C
	movs r1, #1
_0821931C:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082193F6
	movs r0, #0
	bl FUN_0822b644
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r5, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	bl FUN_082412f8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08219394
	ldr r2, _0821938C @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _08219390 @ =0x0000093A
	adds r0, r0, r1
	mov r3, r8
	strh r3, [r0]
	mov r0, r8
	str r0, [r6, #0x5c]
	str r5, [r6, #0x60]
	b _082193CC
	.align 2, 0
_08219388: .4byte 0x000012C8
_0821938C: .4byte 0x030046A0
_08219390: .4byte 0x0000093A
_08219394:
	bl FUN_08241328
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082193BC
	ldr r2, _082193B4 @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _082193B8 @ =0x0000093A
	adds r0, r0, r1
	mov r3, r8
	strh r3, [r0]
	str r4, [r6, #0x5c]
	str r4, [r6, #0x60]
	b _082193CC
	.align 2, 0
_082193B4: .4byte 0x030046A0
_082193B8: .4byte 0x0000093A
_082193BC:
	ldr r2, _0821940C @ =0x030046A0
	ldr r0, [r2]
	ldr r3, _08219410 @ =0x0000093A
	adds r0, r0, r3
	strh r1, [r0]
	mov r0, r8
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
_082193CC:
	movs r1, #2
	ldr r0, [r6, #0x44]
	orrs r0, r1
	str r0, [r6, #0x44]
	ldr r0, [r2]
	ldr r1, _08219410 @ =0x0000093A
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _082193E6
	bl FUN_08231cec
_082193E6:
	adds r0, r6, #0
	bl FUN_08218e4c
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0
	str r0, [r1]
_082193F6:
	ldr r0, [r6, #0x5c]
	cmp r0, #0x63
	bls _08219400
	bl _08219D7E
_08219400:
	lsls r0, r0, #2
	ldr r1, _08219414 @ =_08219418
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821940C: .4byte 0x030046A0
_08219410: .4byte 0x0000093A
_08219414: .4byte _08219418
_08219418: @ jump table
	.4byte _082195A8 @ case 0
	.4byte _0821960A @ case 1
	.4byte _082197A4 @ case 2
	.4byte _0821983A @ case 3
	.4byte _08219900 @ case 4
	.4byte _0821996A @ case 5
	.4byte _082199D4 @ case 6
	.4byte _08219A80 @ case 7
	.4byte _08219B74 @ case 8
	.4byte _08219BB4 @ case 9
	.4byte _08219C04 @ case 10
	.4byte _08219C2A @ case 11
	.4byte _08219C98 @ case 12
	.4byte _08219D7E @ case 13
	.4byte _08219D7E @ case 14
	.4byte _08219D7E @ case 15
	.4byte _08219D7E @ case 16
	.4byte _08219D7E @ case 17
	.4byte _08219D7E @ case 18
	.4byte _08219D7E @ case 19
	.4byte _08219D7E @ case 20
	.4byte _08219D7E @ case 21
	.4byte _08219D7E @ case 22
	.4byte _08219D7E @ case 23
	.4byte _08219D7E @ case 24
	.4byte _08219D7E @ case 25
	.4byte _08219D7E @ case 26
	.4byte _08219D7E @ case 27
	.4byte _08219D7E @ case 28
	.4byte _08219D7E @ case 29
	.4byte _08219D7E @ case 30
	.4byte _08219D7E @ case 31
	.4byte _08219D7E @ case 32
	.4byte _08219D7E @ case 33
	.4byte _08219D7E @ case 34
	.4byte _08219D7E @ case 35
	.4byte _08219D7E @ case 36
	.4byte _08219D7E @ case 37
	.4byte _08219D7E @ case 38
	.4byte _08219D7E @ case 39
	.4byte _08219D7E @ case 40
	.4byte _08219D7E @ case 41
	.4byte _08219D7E @ case 42
	.4byte _08219D7E @ case 43
	.4byte _08219D7E @ case 44
	.4byte _08219D7E @ case 45
	.4byte _08219D7E @ case 46
	.4byte _08219D7E @ case 47
	.4byte _08219D7E @ case 48
	.4byte _08219D7E @ case 49
	.4byte _08219D7E @ case 50
	.4byte _08219D7E @ case 51
	.4byte _08219D7E @ case 52
	.4byte _08219D7E @ case 53
	.4byte _08219D7E @ case 54
	.4byte _08219D7E @ case 55
	.4byte _08219D7E @ case 56
	.4byte _08219D7E @ case 57
	.4byte _08219D7E @ case 58
	.4byte _08219D7E @ case 59
	.4byte _08219D7E @ case 60
	.4byte _08219D7E @ case 61
	.4byte _08219D7E @ case 62
	.4byte _08219D7E @ case 63
	.4byte _08219D7E @ case 64
	.4byte _08219D7E @ case 65
	.4byte _08219D7E @ case 66
	.4byte _08219D7E @ case 67
	.4byte _08219D7E @ case 68
	.4byte _08219D7E @ case 69
	.4byte _08219D7E @ case 70
	.4byte _08219D7E @ case 71
	.4byte _08219D7E @ case 72
	.4byte _08219D7E @ case 73
	.4byte _08219D7E @ case 74
	.4byte _08219D7E @ case 75
	.4byte _08219D7E @ case 76
	.4byte _08219D7E @ case 77
	.4byte _08219D7E @ case 78
	.4byte _08219D7E @ case 79
	.4byte _08219D7E @ case 80
	.4byte _08219D7E @ case 81
	.4byte _08219D7E @ case 82
	.4byte _08219D7E @ case 83
	.4byte _08219D7E @ case 84
	.4byte _08219D7E @ case 85
	.4byte _08219D7E @ case 86
	.4byte _08219D7E @ case 87
	.4byte _08219D7E @ case 88
	.4byte _08219D7E @ case 89
	.4byte _08219D7E @ case 90
	.4byte _08219D7E @ case 91
	.4byte _08219D7E @ case 92
	.4byte _08219D7E @ case 93
	.4byte _08219D7E @ case 94
	.4byte _08219D7E @ case 95
	.4byte _08219D7E @ case 96
	.4byte _08219D7E @ case 97
	.4byte _08219D7E @ case 98
	.4byte _08219D14 @ case 99
_082195A8:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _082195B6
	movs r1, #1
_082195B6:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082195F4
	adds r0, r6, #0
	bl FUN_08219238
	adds r0, r6, #0
	movs r1, #0
	bl FUN_082139b4
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_08047a28
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
_082195F4:
	ldr r0, [r6, #0x60]
	cmp r0, #0x1d
	bgt _082195FC
	b _08219D7E
_082195FC:
	adds r0, r6, #0
	bl FUN_08213a64
	cmp r0, #1
	beq _08219608
	b _08219D7E
_08219608:
	b _08219BF0
_0821960A:
	movs r2, #2
	ldr r1, [r6, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08219616
	movs r2, #1
_08219616:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	cmp r2, #0
	beq _0821967C
	adds r0, r6, #0
	bl FUN_08213a50
	movs r4, #4
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #4
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r4, [r6, #0x64]
	ldr r0, _082196C0 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _082196C4 @ =0x0000093A
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _0821965A
	bl FUN_08231d24
_0821965A:
	adds r0, r6, #0
	bl FUN_08218e90
	ldr r1, _082196C8 @ =0x00000396
	adds r0, r7, r1
	strh r5, [r0]
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r4, r7, r2
	ldr r0, [r4]
	cmp r0, #0
	bne _0821967C
	movs r0, #0xb3
	bl PlaySound_082406e0
	movs r0, #1
	str r0, [r4]
_0821967C:
	adds r0, r6, #0
	bl FUN_08219d98
	ldr r0, _082196CC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _082196D0
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xa
	str r0, [r1]
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #9
	str r0, [r1]
	movs r0, #8
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _08219D7E
	.align 2, 0
_082196C0: .4byte 0x030046A0
_082196C4: .4byte 0x0000093A
_082196C8: .4byte 0x00000396
_082196CC: .4byte 0x030044E0
_082196D0:
	movs r5, #1
	adds r3, r5, #0
	ands r3, r1
	cmp r3, #0
	beq _0821972A
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _08219718
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0xb
	str r0, [r1]
	movs r0, #8
	str r0, [r6, #0x5c]
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	ldr r1, _08219714 @ =0x00000396
	adds r0, r7, r1
	strh r2, [r0]
	adds r0, r6, #0
	bl FUN_08219d98
	movs r0, #0xe0
	bl PlaySound_082406e0
	b _08219D7E
	.align 2, 0
_08219714: .4byte 0x00000396
_08219718:
	str r4, [r6, #0x5c]
	str r2, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _08219D7E
_0821972A:
	ldr r0, _08219764 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08219768 @ =0x0000093A
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0821973C
	b _08219D7E
_0821973C:
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08219770
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0821975C
	strh r5, [r1]
_0821975C:
	ldr r1, _0821976C @ =0x00000396
	adds r0, r7, r1
	strh r3, [r0]
	b _08219796
	.align 2, 0
_08219764: .4byte 0x030046A0
_08219768: .4byte 0x0000093A
_0821976C: .4byte 0x00000396
_08219770:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0821977A
	b _08219D7E
_0821977A:
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08219790
	strh r2, [r1]
_08219790:
	ldr r1, _082197A0 @ =0x00000396
	adds r0, r7, r1
	strh r2, [r0]
_08219796:
	movs r0, #0xdf
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _08219D7E
	.align 2, 0
_082197A0: .4byte 0x00000396
_082197A4:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _082197B2
	movs r1, #1
_082197B2:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08219806
	adds r0, r6, #0
	bl FUN_08219238
	adds r0, r6, #0
	bl FUN_08216cc4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_082139b4
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #4
	bl FUN_08047a28
	movs r0, #1
	movs r1, #6
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r2, _08219824 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0
	strh r1, [r0, #8]
	ldr r0, [r2]
	strh r1, [r0, #0xa]
	ldr r0, [r2]
	strh r1, [r0, #0xe]
_08219806:
	ldr r0, [r6, #0x60]
	cmp r0, #9
	bgt _0821980E
	b _08219D7E
_0821980E:
	adds r0, r6, #0
	bl FUN_08213a64
	cmp r0, #2
	beq _08219832
	cmp r0, #2
	bgt _08219828
	cmp r0, #1
	beq _0821982E
	b _08219D7E
	.align 2, 0
_08219824: .4byte 0x030046A0
_08219828:
	cmp r0, #3
	beq _08219836
	b _08219D7E
_0821982E:
	movs r0, #3
	b _08219BF0
_08219832:
	movs r0, #6
	b _08219BF0
_08219836:
	movs r0, #1
	b _08219BF0
_0821983A:
	movs r7, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r7
	cmp r1, #0
	beq _08219848
	movs r1, #1
_08219848:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082198C6
	adds r0, r6, #0
	bl FUN_08217bcc
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	adds r0, r6, #0
	bl FUN_08213a50
	movs r5, #8
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #8
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r5, [r6, #0x64]
	adds r0, r6, #0
	bl FUN_08216c88
	ldr r3, _082198DC @ =0x00001FE2
	adds r0, r6, r3
	strh r4, [r0]
_082198C6:
	adds r0, r6, #0
	bl FUN_08216f0c
	cmp r0, #2
	beq _082198EC
	cmp r0, #2
	bgt _082198E0
	cmp r0, #1
	beq _082198E6
	b _08219D7E
	.align 2, 0
_082198DC: .4byte 0x00001FE2
_082198E0:
	cmp r0, #3
	beq _082198F2
	b _08219D7E
_082198E6:
	movs r0, #4
	str r0, [r6, #0x5c]
	b _082198F4
_082198EC:
	movs r0, #5
	str r0, [r6, #0x5c]
	b _082198F4
_082198F2:
	str r7, [r6, #0x5c]
_082198F4:
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r7
	str r0, [r6, #0x44]
	b _08219D7E
_08219900:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _0821990E
	movs r1, #1
_0821990E:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08219952
	adds r0, r6, #0
	bl FUN_08219238
	adds r0, r6, #0
	bl FUN_08216cc4
	adds r0, r6, #0
	movs r1, #0
	bl FUN_082139b4
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #5
	bl FUN_08047a28
	movs r0, #3
	movs r1, #7
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
_08219952:
	ldr r0, [r6, #0x60]
	cmp r0, #0x1d
	bgt _0821995A
	b _08219D7E
_0821995A:
	adds r0, r6, #0
	bl FUN_08213a64
	cmp r0, #1
	beq _08219966
	b _08219D7E
_08219966:
	movs r0, #6
	b _08219BF0
_0821996A:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08219978
	movs r1, #1
_08219978:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082199BC
	adds r0, r6, #0
	bl FUN_08219238
	adds r0, r6, #0
	bl FUN_08216cc4
	adds r0, r6, #0
	movs r1, #0
	bl FUN_082139b4
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #6
	bl FUN_08047a28
	movs r0, #1
	movs r1, #8
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
_082199BC:
	ldr r0, [r6, #0x60]
	cmp r0, #0x1d
	bgt _082199C4
	b _08219D7E
_082199C4:
	adds r0, r6, #0
	bl FUN_08213a64
	cmp r0, #1
	beq _082199D0
	b _08219D7E
_082199D0:
	movs r0, #3
	b _08219BF0
_082199D4:
	movs r5, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r5
	cmp r1, #0
	beq _082199E2
	movs r1, #1
_082199E2:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08219A3E
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	adds r0, r6, #0
	bl FUN_08213a50
	adds r0, r6, #0
	bl FUN_08217bb8
	ldr r3, _08219A50 @ =0x00001FE2
	adds r0, r6, r3
	strh r4, [r0]
_08219A3E:
	adds r0, r6, #0
	bl FUN_08217e00
	adds r2, r0, #0
	cmp r2, #1
	beq _08219A54
	cmp r2, #2
	beq _08219A64
	b _08219D7E
	.align 2, 0
_08219A50: .4byte 0x00001FE2
_08219A54:
	movs r0, #7
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r5
	str r0, [r6, #0x44]
	b _08219D7E
_08219A64:
	movs r0, #0x10
	ldr r1, [r6, #0x44]
	ands r0, r1
	cmp r0, #0
	beq _08219A76
	movs r0, #3
	str r0, [r6, #0x5c]
	movs r0, #0
	b _08219A78
_08219A76:
	str r2, [r6, #0x5c]
_08219A78:
	str r0, [r6, #0x60]
	orrs r1, r2
	str r1, [r6, #0x44]
	b _08219D7E
_08219A80:
	movs r0, #2
	mov r8, r0
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq _08219A90
	movs r1, #1
_08219A90:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08219B02
	adds r0, r6, #0
	bl FUN_08217bcc
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r5, #5
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #5
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r5, [r6, #0x64]
	adds r0, r6, #0
	bl FUN_08213b30
_08219B02:
	adds r0, r6, #0
	bl FUN_08213c24
	adds r2, r0, #0
	cmp r2, #2
	beq _08219B50
	cmp r2, #2
	bgt _08219B18
	cmp r2, #1
	beq _08219B1E
	b _08219D7E
_08219B18:
	cmp r2, #3
	beq _08219B62
	b _08219D7E
_08219B1E:
	movs r1, #0x20
	ldr r0, [r6, #0x44]
	ands r0, r1
	cmp r0, #0
	beq _08219B2E
	ldr r0, _08219B4C @ =0x030046A0
	ldr r0, [r0]
	strh r2, [r0, #8]
_08219B2E:
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0xc
	str r0, [r1]
	movs r0, #8
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	mov r3, r8
	orrs r0, r3
	str r0, [r6, #0x44]
	b _08219D7E
	.align 2, 0
_08219B4C: .4byte 0x030046A0
_08219B50:
	movs r0, #6
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	mov r1, r8
	orrs r0, r1
	str r0, [r6, #0x44]
	b _08219D7E
_08219B62:
	movs r0, #6
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	mov r2, r8
	orrs r0, r2
	str r0, [r6, #0x44]
	b _08219D7E
_08219B74:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08219B82
	movs r1, #1
_08219B82:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08219B94
	movs r0, #2
	bl FUN_082403d0
_08219B94:
	ldr r0, [r6, #0x60]
	cmp r0, #0x1f
	bgt _08219B9C
	b _08219D7E
_08219B9C:
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #0
	str r1, [r0]
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	b _08219BF6
_08219BB4:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08219BC2
	movs r1, #1
_08219BC2:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08219BD4
	movs r0, #0x1e
	mov r3, sb
	str r0, [r3, #4]
_08219BD4:
	adds r0, r6, #0
	adds r0, #0x70
	ldr r3, _08219C00 @ =0x0000FFFF
	movs r1, #1
	movs r2, #0x1e
	bl FUN_0821b21c
	cmp r0, #0
	bne _08219BE8
	b _08219D7E
_08219BE8:
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
_08219BF0:
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
_08219BF6:
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	b _08219D7E
	.align 2, 0
_08219C00: .4byte 0x0000FFFF
_08219C04:
	movs r3, #2
	ldr r2, [r6, #0x44]
	adds r0, r2, #0
	ands r0, r3
	movs r1, #3
	rsbs r1, r1, #0
	ands r1, r2
	str r1, [r6, #0x44]
	ldr r0, [r6, #0x60]
	cmp r0, #0x3b
	bgt _08219C1C
	b _08219D7E
_08219C1C:
	movs r0, #0x63
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	orrs r1, r3
	str r1, [r6, #0x44]
	b _08219D7E
_08219C2A:
	movs r0, #2
	ldr r1, [r6, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	ldr r0, [r6, #0x60]
	cmp r0, #0x1e
	beq _08219C40
	b _08219D7E
_08219C40:
	adds r0, r6, #0
	bl FUN_08219238
	ldr r7, _08219C88 @ =0x030046A0
	ldr r0, [r7]
	movs r5, #0x93
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	cmp r0, #0
	bne _08219C58
	b _08219D7E
_08219C58:
	adds r0, r6, #0
	bl FUN_0821572c
	ldr r0, _08219C8C @ =0x0300481C
	movs r4, #0
	str r4, [r0]
	ldr r0, [r6, #0x4c]
	cmp r0, #0
	beq _08219C70
	movs r1, #0
	bl FUN_082318ac
_08219C70:
	ldr r0, _08219C90 @ =0x030044BC
	str r4, [r0]
	ldr r1, _08219C94 @ =0x03004798
	movs r0, #0x11
	str r0, [r1]
	ldr r0, [r7]
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	bl FUN_08231be0
	b _08219D7E
	.align 2, 0
_08219C88: .4byte 0x030046A0
_08219C8C: .4byte 0x0300481C
_08219C90: .4byte 0x030044BC
_08219C94: .4byte 0x03004798
_08219C98:
	movs r2, #2
	ldr r1, [r6, #0x44]
	ands r2, r1
	cmp r2, #0
	beq _08219CA4
	movs r2, #1
_08219CA4:
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	cmp r2, #0
	beq _08219CC2
	adds r0, r6, #0
	bl FUN_0821572c
	ldr r0, _08219D10 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	ldr r0, [r6, #0x48]
	bl FUN_082318ac
_08219CC2:
	ldr r0, [r6, #0x60]
	cmp r0, #0x1e
	bne _08219D7E
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	adds r0, r6, #0
	bl FUN_08213a50
	b _08219D7E
	.align 2, 0
_08219D10: .4byte 0x0300481C
_08219D14:
	movs r0, #2
	ldr r1, [r6, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	ldr r0, [r6, #0x50]
	movs r1, #0
	bl FUN_082318ac
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r0, _08219D8C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _08219D90 @ =0x0000093E
	adds r0, r0, r3
	ldr r2, _08219D94 @ =0x00000E7C
	adds r1, r6, r2
	ldr r1, [r1]
	strh r1, [r0]
	adds r0, r6, #0
	bl KillEntity
_08219D7E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08219D8C: .4byte 0x030046A0
_08219D90: .4byte 0x0000093E
_08219D94: .4byte 0x00000E7C
