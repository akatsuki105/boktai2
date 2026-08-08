	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	ldr r0, _080FA9D8 @ =0x7FFFFFFF
	str r0, [sp, #8]
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	ldr r0, _080FA9DC @ =0x03002C68
	ldr r0, [r0]
	mov r2, sl
	str r2, [sp, #0xc]
	cmp r0, #0
	beq _080FA980
	ldrh r0, [r0, #0x1a]
	str r0, [sp, #0xc]
_080FA980:
	movs r6, #0
	ldr r3, [sp, #0xc]
	cmp r6, r3
	bge _080FAA76
	mov r5, sp
	ldr r7, _080FA9E0 @ =0x03002BE0
	mov sb, r6
_080FA98E:
	ldr r2, [r7]
	cmp r2, #0
	beq _080FAA68
	movs r0, #8
	ldr r1, _080FA9E4 @ =0x03002BC0
	add r1, sb
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _080FAA68
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080FAA68
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080FA9D2
	cmp r1, #0
	blt _080FA9D2
	ldr r0, _080FA9E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080FA9D2
	ldr r0, _080FA9EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FA9F0
_080FA9D2:
	movs r4, #0
	b _080FA9FE
	.align 2, 0
_080FA9D8: .4byte 0x7FFFFFFF
_080FA9DC: .4byte 0x03002C68
_080FA9E0: .4byte 0x03002BE0
_080FA9E4: .4byte 0x03002BC0
_080FA9E8: .4byte 0x030046A8
_080FA9EC: .4byte 0x030046AC
_080FA9F0:
	ldr r0, _080FAA10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080FA9FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FAA14
	adds r0, #4
	b _080FAA20
	.align 2, 0
_080FAA10: .4byte 0x030046A4
_080FAA14:
	ldr r0, _080FAA80 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FAA20:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _080FAA68
	ldr r0, [r7]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	mov r3, r8
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, [sp, #8]
	cmp r1, r0
	bge _080FAA68
	str r1, [sp, #8]
	mov sl, r6
_080FAA68:
	adds r7, #4
	movs r1, #4
	add sb, r1
	adds r6, #1
	ldr r2, [sp, #0xc]
	cmp r6, r2
	blt _080FA98E
_080FAA76:
	mov r3, sl
	cmp r3, #0
	blt _080FAA84
	mov r0, sl
	b _080FAA88
	.align 2, 0
_080FAA80: .4byte 0x030046A4
_080FAA84:
	movs r0, #1
	rsbs r0, r0, #0
_080FAA88:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
