	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r4, #0
	movs r7, #1
	movs r3, #0
	ldr r0, _081DD188 @ =0x00000859
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r4, r0
	bge _081DD1A8
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _081DD18C @ =0x000006EC
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _081DD190 @ =0x000006F4
	adds r5, r6, r2
	ldr r0, _081DD194 @ =0x085AE3CC
	mov sl, r0
	mov ip, r1
_081DD15C:
	mov r1, sb
	adds r0, r1, r3
	strb r4, [r0]
	lsls r1, r3, #1
	mov r0, r8
	adds r2, r0, r1
	lsls r0, r4, #1
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, r5, r1
	adds r2, r3, #1
	lsls r0, r2, #1
	adds r0, r5, r0
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _081DD198
	adds r4, r4, r7
	movs r7, #1
	b _081DD19A
	.align 2, 0
_081DD188: .4byte 0x00000859
_081DD18C: .4byte 0x000006EC
_081DD190: .4byte 0x000006F4
_081DD194: .4byte 0x085AE3CC
_081DD198:
	adds r7, #1
_081DD19A:
	adds r3, r2, #0
	mov r1, ip
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r3, r0
	blt _081DD15C
_081DD1A8:
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r0, r0, r3
	strb r4, [r0]
	lsls r0, r3, #1
	subs r2, #0x14
	adds r1, r6, r2
	adds r1, r1, r0
	lsls r0, r4, #1
	ldr r2, _081DD1D4 @ =0x085AE3CC
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD1D4: .4byte 0x085AE3CC
