	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov r0, sp
	bl FUN_08238e48
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE3B2
	movs r2, #0
	movs r0, #0
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0x28
	strb r0, [r1]
	ldr r0, _081DE3D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE3A0
	adds r0, #0x2c
	strb r2, [r0]
_081DE3A0:
	adds r1, r4, #0
	adds r1, #0x74
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x77
_081DE3AA:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE3AA
_081DE3B2:
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	bge _081DE46C
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _081DE3E0
_081DE3C6:
	ldr r2, _081DE3DC @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl Entity9A9F_SetState
	bl FUN_08238bf4
	b _081DE6D4
	.align 2, 0
_081DE3D8: .4byte 0x03002C68
_081DE3DC: .4byte FUN_081de250
_081DE3E0:
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081DE444
	adds r5, r4, #0
	adds r5, #0x78
	adds r6, r4, #0
	adds r6, #0x23
	adds r1, r4, #0
	adds r1, #0x74
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x77
_081DE3FA:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE3FA
	movs r3, #0
	ldr r0, _081DE42C @ =0x0000FFFF
	mov r8, r0
	movs r7, #0
	adds r2, r4, #0
	adds r2, #0x68
	adds r1, r5, #0
	mov r5, sp
_081DE412:
	ldrh r0, [r5]
	cmp r0, r8
	bne _081DE430
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _081DE422
	adds r0, #1
	strb r0, [r1]
_081DE422:
	ldrb r0, [r1]
	cmp r0, #0x77
	bls _081DE436
	strb r7, [r2]
	b _081DE436
	.align 2, 0
_081DE42C: .4byte 0x0000FFFF
_081DE430:
	strb r7, [r1]
	movs r0, #1
	strb r0, [r2]
_081DE436:
	adds r2, #1
	adds r1, #1
	adds r5, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE412
	b _081DE6C0
_081DE444:
	ldrb r0, [r4, #0x1d]
	adds r6, r4, #0
	adds r6, #0x23
	cmp r0, #0
	beq _081DE450
	b _081DE6C0
_081DE450:
	ldr r0, _081DE468 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081DE45E
	b _081DE6C0
_081DE45E:
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	b _081DE6C0
	.align 2, 0
_081DE468: .4byte 0x030044E0
_081DE46C:
	movs r3, #0
	ldr r7, _081DE498 @ =0x0000FFFF
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0x68
	adds r1, r4, #0
	adds r1, #0x78
	mov r5, sp
_081DE47C:
	ldrh r0, [r5]
	cmp r0, r7
	bne _081DE49C
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _081DE48C
	adds r0, #1
	strb r0, [r1]
_081DE48C:
	ldrb r0, [r1]
	cmp r0, #0x77
	bls _081DE4A2
	strb r6, [r2]
	b _081DE4A2
	.align 2, 0
_081DE498: .4byte 0x0000FFFF
_081DE49C:
	strb r6, [r1]
	movs r0, #1
	strb r0, [r2]
_081DE4A2:
	adds r2, #1
	adds r1, #1
	adds r5, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE47C
	movs r3, #0
	strh r3, [r4, #0x2e]
	ldr r1, [r4, #0x4c]
	lsls r0, r1, #1
	add r0, sp
	ldrh r0, [r0]
	ldr r2, _081DE4F4 @ =0x0000FFFF
	cmp r0, r2
	bne _081DE4C2
	b _081DE3C6
_081DE4C2:
	strh r1, [r4, #0x18]
	strh r3, [r4, #0x1a]
	movs r1, #0
	mov sb, r1
	movs r7, #1
	mov r8, r1
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x2d
	str r0, [sp, #8]
	adds r1, r4, #0
	adds r1, #0x74
	str r1, [sp, #0x10]
	adds r0, #0x3b
	str r0, [sp, #0xc]
	mov sl, r2
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
	adds r6, r0, #0
	ldr r5, [sp, #0x10]
_081DE4EC:
	cmp r3, #0
	bge _081DE4F8
	ldr r0, _081DE4F4 @ =0x0000FFFF
	b _081DE500
	.align 2, 0
_081DE4F4: .4byte 0x0000FFFF
_081DE4F8:
	ldr r1, [r4, #0x44]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DE500:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, sl
	beq _081DE570
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bne _081DE51A
	movs r0, #1
	b _081DE51C
_081DE51A:
	movs r0, #0
_081DE51C:
	cmp r0, #0
	beq _081DE528
	movs r0, #0xff
	ands r0, r2
	cmp r0, #0x3e
	beq _081DE540
_081DE528:
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE53A
	movs r0, #1
	b _081DE53C
_081DE53A:
	movs r0, #0
_081DE53C:
	cmp r0, #0
	beq _081DE56C
_081DE540:
	movs r0, #1
	add sb, r0
	ldrb r0, [r5]
	cmp r0, #0xfe
	bhi _081DE54E
	adds r0, #1
	strb r0, [r5]
_081DE54E:
	ldrb r0, [r5]
	cmp r0, #0x59
	bls _081DE564
	movs r0, #2
	strb r0, [r6]
	cmp r7, #0
	beq _081DE58C
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _081DE58C
_081DE564:
	movs r7, #0
	movs r0, #1
	strb r0, [r6]
	b _081DE58C
_081DE56C:
	cmp r2, sl
	bne _081DE574
_081DE570:
	movs r0, #0
	b _081DE57A
_081DE574:
	movs r1, #1
	mov r8, r1
	mov r0, r8
_081DE57A:
	strb r0, [r6]
	movs r7, #0
	strb r7, [r5]
	ldr r0, _081DE5D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE58C
	adds r0, #0x2c
	strb r7, [r0]
_081DE58C:
	adds r6, #1
	adds r5, #1
	adds r3, #1
	cmp r3, #3
	ble _081DE4EC
	mov r1, r8
	cmp r1, #0
	beq _081DE5C2
	movs r3, #0
	ldr r0, _081DE5DC @ =0x0000FFFF
	mov ip, r0
	mov r1, sp
	ldr r5, [sp, #0xc]
	movs r7, #1
	ldr r2, [sp, #0x10]
	movs r6, #0
_081DE5AC:
	ldrh r0, [r1]
	cmp r0, ip
	beq _081DE5B6
	adds r0, r5, r3
	strb r7, [r0]
_081DE5B6:
	adds r0, r2, r3
	strb r6, [r0]
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE5AC
_081DE5C2:
	ldr r0, [r4, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE5E0
	movs r0, #1
	b _081DE5E2
	.align 2, 0
_081DE5D8: .4byte 0x03002C68
_081DE5DC: .4byte 0x0000FFFF
_081DE5E0:
	movs r0, #0
_081DE5E2:
	cmp r0, #0
	beq _081DE654
	ldr r0, _081DE624 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE5F6
	adds r1, r0, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_081DE5F6:
	ldr r1, [sp, #8]
	ldrb r0, [r1]
	cmp r0, #0
	beq _081DE628
	subs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldrb r0, [r4, #0x1d]
	adds r6, r4, #0
	adds r6, #0x23
	cmp r0, #0
	bne _081DE6C0
	movs r0, #3
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	b _081DE6C0
	.align 2, 0
_081DE624: .4byte 0x03002C68
_081DE628:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldr r2, _081DE650 @ =FUN_081de6f0
	adds r0, r4, #0
	movs r1, #5
	bl Entity9A9F_SetState
	adds r0, r4, #0
	bl FUN_081dd9f0
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DE6D4
	.align 2, 0
_081DE650: .4byte FUN_081de6f0
_081DE654:
	movs r0, #0x28
	ldr r1, [sp, #8]
	strb r0, [r1]
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _081DE6B4
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldr r0, _081DE6AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	adds r3, r4, #0
	adds r3, #0x28
	cmp r0, #0
	bne _081DE686
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DE6A4
_081DE686:
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r2, r4, #0
	adds r2, #0x42
	movs r0, #0
	strh r1, [r2]
	strb r0, [r3]
	ldr r0, _081DE6B0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE6A4
	adds r1, r0, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_081DE6A4:
	movs r0, #3
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	b _081DE6BC
	.align 2, 0
_081DE6AC: .4byte 0x030044E0
_081DE6B0: .4byte 0x03002C68
_081DE6B4:
	ldr r0, _081DE6E8 @ =0x0000043E
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
_081DE6BC:
	adds r6, r4, #0
	adds r6, #0x23
_081DE6C0:
	ldrb r0, [r6]
	cmp r0, #2
	bne _081DE6D4
	bl FUN_08238c24
	ldr r2, _081DE6EC @ =FUN_081de214
	adds r0, r4, #0
	movs r1, #1
	bl Entity9A9F_SetState
_081DE6D4:
	movs r0, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DE6E8: .4byte 0x0000043E
_081DE6EC: .4byte FUN_081de214
