	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r2, r0, #0
	mov r8, r1
	ldr r0, _080EDB84 @ =0x7FFFFFFF
	mov sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	ldr r3, _080EDB88 @ =0x000001DF
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _080EDB8C
	movs r1, #0x80
	lsls r1, r1, #0x13
	subs r3, #0x63
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080EDC20
	b _080EDC2C
	.align 2, 0
_080EDB84: .4byte 0x7FFFFFFF
_080EDB88: .4byte 0x000001DF
_080EDB8C:
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r3, _080EDC24 @ =0x00000252
	adds r0, r2, r3
	ldrb r2, [r0]
	mov r0, sp
	bl FUN_08234f90
	movs r5, #0
	add r3, sp, #8
	mov r4, sp
	ldr r0, _080EDC28 @ =0x03002BE0
	mov ip, r0
_080EDBAA:
	mov r1, ip
	ldr r0, [r1]
	cmp r0, #0
	beq _080EDBEE
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp sb, r1
	ble _080EDBEE
	mov sb, r1
	mov sl, r5
	ldr r6, [sp, #8]
	ldr r7, [sp, #0xc]
_080EDBEE:
	movs r0, #4
	add ip, r0
	adds r5, #1
	cmp r5, #3
	ble _080EDBAA
	mov r1, sl
	cmp r1, #0
	blt _080EDC2C
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _080EDC2C
	cmn r1, r0
	blt _080EDC2C
	lsls r0, r7, #0x10
	asrs r1, r0, #0x10
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _080EDC2C
	cmn r1, r0
	blt _080EDC2C
_080EDC20:
	movs r0, #1
	b _080EDC2E
	.align 2, 0
_080EDC24: .4byte 0x00000252
_080EDC28: .4byte 0x03002BE0
_080EDC2C:
	movs r0, #0
_080EDC2E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
