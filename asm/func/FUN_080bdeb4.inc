	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r1, _080BDF70 @ =0x00001690
	adds r0, r7, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BDF60
	ldr r2, _080BDF74 @ =0x00001787
	adds r0, r7, r2
	ldrb r0, [r0]
	mov sb, r0
	ldr r3, _080BDF78 @ =0x0000178A
	adds r0, r7, r3
	ldrb r4, [r0]
	subs r4, #0x10
	ldr r6, _080BDF7C @ =0x08DA9E68
	mov r8, r6
	ldr r0, _080BDF80 @ =0x00001654
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r4, r0
	ldr r1, _080BDF84 @ =0x0000165C
	adds r5, r7, r1
	adds r0, r5, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, sp
	add r1, r8
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #0x18]
	adds r0, r7, #0
	bl FUN_080bd01c
	mov r0, sb
	mov r1, sp
	bl FUN_08242b6c
	ldr r0, _080BDF88 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0x91
	lsls r0, r0, #4
	adds r2, r2, r0
	mov r1, sl
	ldrb r0, [r1]
	lsls r0, r0, #4
	adds r4, r4, r0
	adds r5, r5, r4
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r2]
	ldrh r0, [r0, #0xa]
	subs r1, r1, r0
	strh r1, [r2]
	ldr r2, _080BDF8C @ =0x00001658
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BDF90 @ =0x00000111
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080bd964
_080BDF60:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BDF70: .4byte 0x00001690
_080BDF74: .4byte 0x00001787
_080BDF78: .4byte 0x0000178A
_080BDF7C: .4byte 0x08DA9E68
_080BDF80: .4byte 0x00001654
_080BDF84: .4byte 0x0000165C
_080BDF88: .4byte 0x030046A0
_080BDF8C: .4byte 0x00001658
_080BDF90: .4byte 0x00000111
