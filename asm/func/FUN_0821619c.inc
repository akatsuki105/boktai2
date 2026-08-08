	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x70
	adds r0, r0, r6
	mov sb, r0
	ldr r1, _0821625C @ =0x00000E8C
	adds r7, r6, r1
	movs r0, #1
	mov r8, r0
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq _082161C2
	movs r1, #1
_082161C2:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _08216248
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
	movs r5, #0xa
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #0xa
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	str r5, [r6, #0x64]
	adds r0, r6, #0
	bl FUN_08215f98
	adds r0, r6, #0
	bl FUN_08215d24
	adds r0, r6, #0
	bl FUN_08216000
	adds r0, r6, #0
	bl FUN_0821605c
	adds r0, r6, #0
	bl FUN_082160d8
	str r4, [r6, #0x68]
_08216248:
	ldr r4, [r6, #0x5c]
	cmp r4, #1
	bne _08216250
	b _08216398
_08216250:
	cmp r4, #1
	bgt _08216260
	cmp r4, #0
	beq _0821626E
	b _082164C4
	.align 2, 0
_0821625C: .4byte 0x00000E8C
_08216260:
	cmp r4, #2
	bne _08216266
	b _082163DC
_08216266:
	cmp r4, #0x63
	bne _0821626C
	b _082163FE
_0821626C:
	b _082164C4
_0821626E:
	movs r5, #2
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	ands r0, r5
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	ldr r0, _082162A8 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _082162AC
	adds r0, r6, #0
	bl FUN_0821660c
	cmp r0, #0
	beq _082162AC
	mov r1, r8
	str r1, [r6, #0x5c]
	str r4, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r5
	str r0, [r6, #0x44]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _082164C4
	.align 2, 0
_082162A8: .4byte 0x030044E0
_082162AC:
	adds r0, r6, #0
	bl FUN_08216894
	ldr r4, _082162F4 @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _082162C4
	adds r0, r6, #0
	bl FUN_082164e4
_082162C4:
	ldrh r1, [r4, #2]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _082162FC
	ldr r0, _082162F8 @ =0x00000424
	adds r1, r7, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bge _082162E4
	movs r0, #2
	str r0, [r1]
_082162E4:
	adds r0, r6, #0
	bl FUN_08216154
	movs r0, #0xdf
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _08216322
	.align 2, 0
_082162F4: .4byte 0x030044E0
_082162F8: .4byte 0x00000424
_082162FC:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08216322
	ldr r0, _08216340 @ =0x00000424
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	cmp r0, #2
	ble _08216314
	str r2, [r1]
_08216314:
	adds r0, r6, #0
	bl FUN_08216154
	movs r0, #0xdf
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08216322:
	movs r4, #0
	movs r2, #5
	ldr r5, _08216344 @ =0x030044E0
	ldrh r1, [r5, #2]
	movs r0, #0x20
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	bne _08216378
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08216348
	movs r4, #2
	b _0821637E
	.align 2, 0
_08216340: .4byte 0x00000424
_08216344: .4byte 0x030044E0
_08216348:
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0821637C
	ldr r0, [r6, #0x68]
	adds r0, #1
	str r0, [r6, #0x68]
	cmp r0, #0xe
	ble _0821637E
	cmp r0, #0xc7
	ble _08216362
	movs r2, #2
_08216362:
	adds r1, r2, #0
	bl Mod
	cmp r0, #0
	bne _0821637E
	ldrh r1, [r5]
	mov r0, r8
	ands r0, r1
	movs r4, #2
	cmp r0, #0
	beq _0821637E
_08216378:
	movs r4, #1
	b _0821637E
_0821637C:
	str r4, [r6, #0x68]
_0821637E:
	cmp r4, #1
	bne _0821638A
	adds r0, r6, #0
	bl FUN_08216730
	b _082164C4
_0821638A:
	cmp r4, #2
	beq _08216390
	b _082164C4
_08216390:
	adds r0, r6, #0
	bl FUN_082167dc
	b _082164C4
_08216398:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _082163A6
	movs r1, #1
_082163A6:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082163B8
	movs r0, #0x1e
	mov r1, sb
	str r0, [r1, #4]
_082163B8:
	ldr r3, _082163D8 @ =0x0000FFFF
	mov r0, sb
	movs r1, #1
	movs r2, #0x1e
	bl FUN_0821b21c
	cmp r0, #0
	bne _082163CA
	b _082164C4
_082163CA:
	str r4, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	b _082164C4
	.align 2, 0
_082163D8: .4byte 0x0000FFFF
_082163DC:
	ldr r2, [r6, #0x44]
	adds r0, r2, #0
	ands r0, r4
	movs r1, #3
	rsbs r1, r1, #0
	ands r1, r2
	str r1, [r6, #0x44]
	ldr r0, [r6, #0x60]
	cmp r0, #0x3b
	ble _082164C4
	movs r0, #0x63
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	orrs r1, r4
	str r1, [r6, #0x44]
	b _082164C4
_082163FE:
	movs r0, #2
	ldr r1, [r6, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	ldr r0, [r7, #8]
	mov r1, r8
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	orrs r0, r1
	str r0, [r7, #0x68]
	ldr r0, _082164AC @ =0x00000E7C
	adds r7, r6, r0
	movs r5, #1
	ldr r1, _082164B0 @ =0x00001194
	adds r3, r6, r1
	ldr r0, _082164B4 @ =0x00001074
	adds r2, r6, r0
	ldr r0, _082164B8 @ =0x00000F54
	adds r1, r6, r0
	movs r4, #2
_0821642E:
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
	ldr r0, [r3]
	orrs r0, r5
	str r0, [r3]
	adds r3, #0x60
	adds r2, #0x60
	adds r1, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0821642E
	movs r4, #0
	bl FUN_082407b8
	ldr r0, [r6, #0x50]
	movs r1, #0
	bl FUN_082318ac
	movs r0, #0
	bl FUN_0822b644
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
	ldr r0, _082164BC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _082164C0 @ =0x0000093E
	adds r0, r0, r1
	ldr r1, [r7]
	strh r1, [r0]
	adds r0, r6, #0
	bl KillEntity
	b _082164D4
	.align 2, 0
_082164AC: .4byte 0x00000E7C
_082164B0: .4byte 0x00001194
_082164B4: .4byte 0x00001074
_082164B8: .4byte 0x00000F54
_082164BC: .4byte 0x030046A0
_082164C0: .4byte 0x0000093E
_082164C4:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	bgt _082164D4
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	bl FUN_082372cc
_082164D4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
