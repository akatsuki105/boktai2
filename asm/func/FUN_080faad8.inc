	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r0, #0x9c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	mov sb, r1
	mov sl, r1
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r7, #0xc
	ldrsh r1, [r2, r7]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _080FABCC @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r6, #0
	ldrsh r1, [r1, r6]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _080FABD0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r7
	orrs r1, r2
	str r1, [sp]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #4]
	mov r3, r8
	ldr r0, [r3, #4]
	bl FUN_08234f6c
	adds r4, r0, #0
	movs r6, #0
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp sb, r0
	bge _080FABE2
	mov ip, r7
	add r3, sp, #8
	mov r2, sp
	str r2, [sp, #0x10]
_080FAB70:
	ldrh r1, [r4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	mov r7, ip
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r3, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x10]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r1, r0, r1
	ldr r0, [sp, #0x10]
	movs r7, #4
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bge _080FABD4
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	beq _080FABD6
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _080FAC44
	.align 2, 0
_080FABCC: .4byte 0x085B0A08
_080FABD0: .4byte 0xFFFF0000
_080FABD4:
	adds r4, #8
_080FABD6:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _080FAB70
_080FABE2:
	mov r2, sl
	cmp r2, #0
	bne _080FAC44
	adds r4, r5, #0
	adds r4, #0x9c
	ldr r2, _080FAC38 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080FAC3C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080FAC40 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r6, [r4, #2]
	cmp r0, r6
	bne _080FAC20
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080FAC20:
	strb r0, [r4, #2]
	mov r7, sl
	strb r7, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	b _080FAC54
	.align 2, 0
_080FAC38: .4byte 0x030046B8
_080FAC3C: .4byte 0x000003FF
_080FAC40: .4byte 0x0203B400
_080FAC44:
	movs r0, #0
	mov r2, sb
	mov r1, r8
	strb r2, [r1, #2]
	strb r0, [r1, #3]
	str r4, [r1, #8]
	adds r4, r5, #0
	adds r4, #0x9c
_080FAC54:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r6, [r0]
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r4, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080FAC88
	cmp r1, #0
	blt _080FAC88
	ldr r0, _080FAC8C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080FAC88
	ldr r0, _080FAC90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FAC94
_080FAC88:
	movs r4, #0
	b _080FACA2
	.align 2, 0
_080FAC8C: .4byte 0x030046A8
_080FAC90: .4byte 0x030046AC
_080FAC94:
	ldr r0, _080FACB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080FACA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FACB8
	adds r0, #4
	b _080FACC4
	.align 2, 0
_080FACB4: .4byte 0x030046A4
_080FACB8:
	ldr r0, _080FACD8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FACC4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FACDC
	cmp r2, #2
	beq _080FACE0
	b _080FACE4
	.align 2, 0
_080FACD8: .4byte 0x030046A4
_080FACDC:
	ldrb r0, [r6, #4]
	b _080FACE2
_080FACE0:
	ldrb r0, [r6]
_080FACE2:
	subs r1, r1, r0
_080FACE4:
	strh r1, [r6, #2]
	ldr r6, _080FAD10 @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FAD14
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080FAD3A
	.align 2, 0
_080FAD10: .4byte 0x000004A4
_080FAD14:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FAD34
	cmp r0, #2
	beq _080FAD30
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FAD30:
	movs r0, #1
	b _080FAD44
_080FAD34:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_080FAD3A:
	ldr r1, _080FAD98 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080FAD44:
	adds r4, r0, #0
	cmp r4, #0
	bne _080FADB8
	ldr r1, _080FAD9C @ =FUN_080e48d0
	ldr r6, _080FADA0 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _080FADA4 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _080FADA8 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _080FADAC @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _080FADB0 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _080FADB4 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #4
	adds r0, r5, r6
	strb r3, [r0]
	b _080FADC4
	.align 2, 0
_080FAD98: .4byte 0xFFFFFDFF
_080FAD9C: .4byte FUN_080e48d0
_080FADA0: .4byte 0x0000046D
_080FADA4: .4byte 0x0000046B
_080FADA8: .4byte 0x00000553
_080FADAC: .4byte 0x00000469
_080FADB0: .4byte 0x0000046A
_080FADB4: .4byte 0x00000484
_080FADB8:
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_080FADC4:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
