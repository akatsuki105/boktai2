	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x18
	movs r0, #0
	mov r8, r0
	ldr r1, _080499B4 @ =0x0000017B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080499D4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080499CE
	ldr r0, _080499B8 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080499BC
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #4
	rsbs r2, r2, #0
	ands r1, r2
	adds r1, #4
	str r1, [r0]
	b _080499C8
	.align 2, 0
_080499B4: .4byte 0x0000017B
_080499B8: .4byte 0x030044E0
_080499BC:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080499C8:
	movs r0, #1
	mov r8, r0
	b _080499EA
_080499CE:
	subs r0, #1
	strb r0, [r1]
	b _080499EA
_080499D4:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #8
	rsbs r2, r2, #0
	ands r1, r2
	adds r1, #8
	str r1, [r0]
	movs r2, #1
	mov r8, r2
_080499EA:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080499FC
	b _08049C1A
_080499FC:
	ldr r2, _08049AE8 @ =0x0000017B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049A1E
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _08049A1E
	ldr r0, _08049AEC @ =0x0000017D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08049A1E
	strb r2, [r1]
_08049A1E:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08049A70
	ldr r2, _08049AE8 @ =0x0000017B
	adds r6, r5, r2
	ldrb r0, [r6]
	cmp r0, #0
	bne _08049A70
	subs r1, #8
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x1f
	bne _08049A70
	adds r2, #9
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #8
	bne _08049A70
	adds r0, r7, #0
	bl FUN_0804960c
	cmp r0, #0
	beq _08049A70
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08049A70
	ldr r0, [r4]
	subs r0, #8
	str r0, [r4]
	movs r0, #1
	strb r0, [r6]
	ldr r2, _08049AEC @ =0x0000017D
	adds r1, r5, r2
	strb r0, [r1]
_08049A70:
	ldr r1, _08049AEC @ =0x0000017D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049A7C
	b _08049C1A
_08049A7C:
	mov r2, r8
	cmp r2, #0
	bne _08049A84
	b _08049C1A
_08049A84:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #0x12
	movs r2, #1
	movs r3, #2
	bl FUN_0822ea60
	ldr r0, [r4]
	movs r1, #0x12
	movs r2, #1
	movs r3, #2
	bl FUN_0822eadc
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_0804960c
	adds r4, r0, #0
	cmp r4, #0
	bne _08049AB6
	b _08049BEA
_08049AB6:
	ldrb r0, [r4]
	cmp r0, #0x3c
	bne _08049AF0
	adds r0, r7, #0
	bl TextRenderer_Advance
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08049AF0
	adds r0, r7, #0
	bl FUN_0804960c
	adds r4, r0, #0
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _08049AB6
	ldrb r0, [r4]
	cmp r0, #0
	bne _08049AB6
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	str r0, [r1]
	b _08049AB6
	.align 2, 0
_08049AE8: .4byte 0x0000017B
_08049AEC: .4byte 0x0000017D
_08049AF0:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _08049B54
	adds r0, r5, #0
	adds r0, #0x18
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, [r4]
	movs r2, #2
	str r2, [sp]
	movs r2, #0x12
	movs r3, #1
	bl TextRenderer_SetRect
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0
	ble _08049B44
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08048a20
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bgt _08049BEA
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	movs r0, #0
	str r0, [r4]
	b _08049BEA
_08049B44:
	adds r0, r7, #0
	bl TextRenderer_Advance
	cmp r0, #0
	beq _08049BEA
	movs r0, #8
	str r0, [r4]
	b _08049BEA
_08049B54:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08049B76
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08049B86
	b _08049BEA
_08049B76:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #8
	bne _08049BEA
_08049B86:
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r0, [r6]
	cmp r0, #0
	ble _08049BBE
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08048a20
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
	cmp r0, #0
	bgt _08049BEA
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	movs r0, #0
	b _08049BE8
_08049BBE:
	adds r0, r5, #0
	adds r0, #0x18
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, [r4]
	movs r2, #2
	str r2, [sp]
	movs r2, #0x12
	movs r3, #2
	bl TextRenderer_SetRect
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
	adds r0, r7, #0
	bl TextRenderer_Advance
	cmp r0, #0
	beq _08049BEA
	movs r0, #8
_08049BE8:
	str r0, [r6]
_08049BEA:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1f
	ble _08049C0A
	ldr r0, _08049C38 @ =0x0000017B
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _08049C04
	movs r0, #1
	strb r0, [r2]
_08049C04:
	ldr r0, [r1]
	subs r0, #0x20
	str r0, [r1]
_08049C0A:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1f
	ble _08049C1A
	subs r0, #0x20
	str r0, [r1]
_08049C1A:
	ldr r1, _08049C38 @ =0x0000017B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08049C2A
	adds r0, r5, #0
	bl FUN_0804996c
_08049C2A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08049C38: .4byte 0x0000017B
