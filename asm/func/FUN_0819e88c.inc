	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0819E900 @ =0x00000ECC
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _0819E8BE
	ldr r3, _0819E904 @ =0x00000ECB
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0819E908 @ =0x00000ECA
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x80
	ldr r0, _0819E90C @ =0x00000E48
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	strb r2, [r5]
_0819E8BE:
	ldr r1, _0819E910 @ =0x00000ECD
	adds r3, r4, r1
	ldrb r0, [r3]
	ldr r2, _0819E90C @ =0x00000E48
	adds r5, r4, r2
	cmp r0, #0
	beq _0819E8EE
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5]
	orrs r0, r1
	movs r1, #0x81
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r0, _0819E904 @ =0x00000ECB
	adds r1, r4, r0
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0819E908 @ =0x00000ECA
	adds r0, r4, r1
	strb r2, [r0]
	strb r2, [r3]
_0819E8EE:
	movs r1, #0xc0
	lsls r1, r1, #1
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0819E914
	movs r0, #1
	b _0819E916
	.align 2, 0
_0819E900: .4byte 0x00000ECC
_0819E904: .4byte 0x00000ECB
_0819E908: .4byte 0x00000ECA
_0819E90C: .4byte 0x00000E48
_0819E910: .4byte 0x00000ECD
_0819E914:
	movs r0, #0
_0819E916:
	cmp r0, #0
	beq _0819E9FE
	ldr r1, [r6, #0x44]
	movs r0, #0xfa
	strh r0, [r1, #0x32]
	ldr r1, [r6, #0x44]
	ldr r2, _0819E93C @ =0x0000093C
	adds r0, r4, r2
	str r0, [r1, #0x38]
	ldr r3, _0819E940 @ =0x00000ECB
	adds r0, r4, r3
	ldrb r1, [r0]
	cmp r1, #1
	beq _0819E95C
	cmp r1, #1
	bgt _0819E944
	cmp r1, #0
	beq _0819E94E
	b _0819E97C
	.align 2, 0
_0819E93C: .4byte 0x0000093C
_0819E940: .4byte 0x00000ECB
_0819E944:
	cmp r1, #2
	beq _0819E968
	cmp r1, #3
	beq _0819E974
	b _0819E97C
_0819E94E:
	ldr r2, _0819E958 @ =0x0000093E
	adds r0, r4, r2
	strh r1, [r0]
	b _0819E97C
	.align 2, 0
_0819E958: .4byte 0x0000093E
_0819E95C:
	ldr r3, _0819E964 @ =0x0000093E
	adds r1, r4, r3
	movs r0, #0x10
	b _0819E97A
	.align 2, 0
_0819E964: .4byte 0x0000093E
_0819E968:
	ldr r0, _0819E970 @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0x18
	b _0819E97A
	.align 2, 0
_0819E970: .4byte 0x0000093E
_0819E974:
	ldr r2, _0819E99C @ =0x0000093E
	adds r1, r4, r2
	movs r0, #0x1f
_0819E97A:
	strh r0, [r1]
_0819E97C:
	ldr r3, _0819E9A0 @ =0x00000ECA
	adds r1, r4, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0819E9FE
	movs r1, #0x80
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0819E9A4
	movs r0, #1
	b _0819E9A6
	.align 2, 0
_0819E99C: .4byte 0x0000093E
_0819E9A0: .4byte 0x00000ECA
_0819E9A4:
	movs r0, #0
_0819E9A6:
	cmp r0, #0
	bne _0819E9E8
	ldr r0, _0819E9DC @ =0x00000ECB
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819E9F6
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	ldr r2, _0819E9E0 @ =0x0000047A
	adds r1, r6, r2
	ldrh r1, [r1]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	ldr r1, _0819E9E4 @ =0xFFFFFEFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	b _0819E9FE
	.align 2, 0
_0819E9DC: .4byte 0x00000ECB
_0819E9E0: .4byte 0x0000047A
_0819E9E4: .4byte 0xFFFFFEFF
_0819E9E8:
	ldr r0, _0819EA04 @ =0x00000ECB
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0819E9F6
	adds r0, #1
	strb r0, [r1]
_0819E9F6:
	ldr r2, _0819EA08 @ =0x00000ECA
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0819E9FE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819EA04: .4byte 0x00000ECB
_0819EA08: .4byte 0x00000ECA
