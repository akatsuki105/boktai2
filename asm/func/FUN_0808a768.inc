	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	mov sl, r2
	str r3, [sp, #0x14]
	movs r0, #0x9e
	lsls r0, r0, #4
	add r0, r8
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r3, _0808A79C @ =0x0000036A
	adds r0, r0, r3
	ldrh r2, [r0]
	cmp r1, #0
	bne _0808A7A0
	movs r5, #0
	mov sb, r5
	b _0808A7BA
	.align 2, 0
_0808A79C: .4byte 0x0000036A
_0808A7A0:
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r0, #1
	asrs r5, r0, #3
	lsls r1, r5, #3
	subs r0, r0, r1
	mov sb, r0
_0808A7BA:
	movs r0, #0x9e
	lsls r0, r0, #4
	add r0, r8
	ldr r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r4, #0x1f
	cmp r0, #5
	beq _0808A7D2
	ldr r4, _0808A810 @ =0x0000035F
_0808A7D2:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0808A81C
	movs r7, #0x53
	movs r0, #0x4b
	str r0, [sp, #0x18]
	movs r6, #0x4c
	movs r1, #0x60
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0808A802
	ldr r0, _0808A814 @ =0x00000A02
	add r0, r8
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0808A802
	ldr r4, _0808A818 @ =0x00007FFF
_0808A802:
	movs r0, #0
	mov r1, sl
	ldr r2, [sp, #0x14]
	bl FUN_0808a420
	adds r3, r0, #0
	b _0808A83A
	.align 2, 0
_0808A810: .4byte 0x0000035F
_0808A814: .4byte 0x00000A02
_0808A818: .4byte 0x00007FFF
_0808A81C:
	movs r7, #0x73
	movs r1, #0x6b
	str r1, [sp, #0x18]
	ldr r6, _0808A940 @ =0x000004BD
	mov r1, sl
	subs r1, #1
	movs r0, #0
	ldr r2, [sp, #0x14]
	bl FUN_0808a420
	adds r3, r0, #0
	ldr r2, _0808A944 @ =0x0000D0BD
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
_0808A83A:
	ldr r2, _0808A948 @ =0x03004408
	ldrh r1, [r2]
	cmp r1, r4
	beq _0808A844
	strh r4, [r2]
_0808A844:
	movs r4, #0
	ldr r1, _0808A94C @ =0x030047A4
	mov sl, r1
	cmp r4, r5
	bge _0808A864
	ldr r2, _0808A950 @ =0xFFFFD000
	adds r1, r2, #0
	adds r2, r7, #0
	orrs r2, r1
	adds r4, r5, #0
_0808A858:
	strh r2, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne _0808A858
	adds r4, r5, #0
_0808A864:
	mov r5, sb
	cmp r5, #0
	beq _0808A87C
	mov r1, sb
	subs r1, #8
	subs r1, r7, r1
	ldr r5, _0808A950 @ =0xFFFFD000
	adds r2, r5, #0
	orrs r1, r2
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
_0808A87C:
	cmp r4, #9
	bgt _0808A892
	ldr r2, _0808A950 @ =0xFFFFD000
	adds r1, r2, #0
	ldr r5, [sp, #0x18]
	orrs r1, r5
_0808A888:
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #9
	ble _0808A888
_0808A892:
	ldr r1, _0808A950 @ =0xFFFFD000
	adds r7, r1, #0
	orrs r6, r7
	strh r6, [r3]
	mov r2, sl
	ldr r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #5
	ands r1, r2
	cmp r1, #0
	bne _0808A98C
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0808A98C
	movs r1, #0x9e
	lsls r1, r1, #4
	add r1, r8
	ldr r1, [r1]
	movs r2, #8
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r1, r5
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	beq _0808A95C
	ldr r5, _0808A954 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl Div
	str r0, [sp]
	ldr r2, [r5]
	adds r2, r2, r4
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r4, [r2]
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	movs r0, #0
	movs r1, #9
	movs r2, #3
	bl FUN_0808a420
	adds r4, r0, #0
	mov r6, sp
	movs r5, #3
_0808A922:
	ldm r6!, {r0}
	movs r1, #0
	bl FUN_0808a440
	adds r1, r0, #0
	orrs r1, r7
	strh r1, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0808A922
	ldr r2, _0808A958 @ =0x00000A2F
	add r2, r8
	movs r1, #1
	b _0808A98A
	.align 2, 0
_0808A940: .4byte 0x000004BD
_0808A944: .4byte 0x0000D0BD
_0808A948: .4byte 0x03004408
_0808A94C: .4byte 0x030047A4
_0808A950: .4byte 0xFFFFD000
_0808A954: .4byte 0x030046A0
_0808A958: .4byte 0x00000A2F
_0808A95C:
	ldr r1, _0808A99C @ =0x00000A2F
	add r1, r8
	ldrb r1, [r1]
	cmp r1, #0
	beq _0808A98C
	movs r0, #0
	movs r1, #9
	movs r2, #3
	bl FUN_0808a420
	adds r1, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r3, r2, #0
	movs r2, #3
_0808A97A:
	strh r3, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0808A97A
	ldr r2, _0808A99C @ =0x00000A2F
	add r2, r8
	movs r1, #0
_0808A98A:
	strb r1, [r2]
_0808A98C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A99C: .4byte 0x00000A2F
