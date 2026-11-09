	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov r8, r1
	mov r5, sp
	ldr r2, [r1, #8]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082472B0
	asrs r0, r0, #8
	b _082472B6
_082472B0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082472B6:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082472C8
	asrs r0, r0, #8
	b _082472CE
_082472C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082472CE:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _082472E2
	asrs r0, r0, #8
	b _082472E8
_082472E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082472E8:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08247364 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldr r1, _08247368 @ =0x08DBD830
	mov sb, r1
	mov r6, sp
	mov r5, r8
	adds r5, #0xc
	adds r4, r5, #0
	movs r7, #3
_08247314:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	mov r0, sl
	mov r1, r8
	adds r2, r5, #0
	bl _call_via_r3
	ldrb r0, [r4]
	cmp r0, #0
	beq _0824734A
	ldrh r0, [r4, #8]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0xc]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_0824734A:
	adds r4, #0x48
	adds r5, #0x48
	subs r7, #1
	cmp r7, #0
	bge _08247314
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08247364: .4byte 0x030047C8
_08247368: .4byte 0x08DBD830
