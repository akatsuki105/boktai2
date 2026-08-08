	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl FUN_080ef840
	ldr r0, _080ED7DC @ =0x03002C60
	ldr r5, [r0]
	ldr r4, [r5, #4]
	cmp r4, #0
	beq _080ED7CE
	movs r0, #5
	mov sb, r0
	movs r6, #0
	movs r7, #1
	movs r1, #3
	mov r8, r1
_080ED746:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ED7C6
	ldr r2, _080ED7E0 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	beq _080ED768
	cmp r0, #1
	beq _080ED768
	cmp r0, #3
	beq _080ED768
	cmp r0, #0xa
	bne _080ED7C6
_080ED768:
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _080ED7E4 @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r6, [r0]
	adds r2, #0xe8
	adds r0, r4, r2
	mov r2, sb
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r6, [r0]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r6, [r0]
	ldr r1, _080ED7E8 @ =0x00000469
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	mov r1, r8
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r6, [r0]
	ldr r1, _080ED7EC @ =0x0000046C
	adds r0, r4, r1
	strb r7, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080ED7C6:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	cmp r4, #0
	bne _080ED746
_080ED7CE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ED7DC: .4byte 0x03002C60
_080ED7E0: .4byte 0x000001DF
_080ED7E4: .4byte 0x0000046D
_080ED7E8: .4byte 0x00000469
_080ED7EC: .4byte 0x0000046C
