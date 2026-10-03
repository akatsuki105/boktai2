	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sl, r1
	mov sb, r2
	ldr r0, _0808FE9C @ =0x00004034
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	beq _0808FF6C
	movs r7, #0
	b _0808FF52
	.align 2, 0
_0808FE9C: .4byte 0x00004034
_0808FEA0:
	ldr r1, _0808FF00 @ =0x00004038
	add r1, r8
	ldrb r0, [r6, #1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0808FF50
	ldr r0, _0808FF04 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r7
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808FF50
	ldrb r3, [r6, #2]
	ldrb r2, [r6, #3]
	cmp r3, sl
	blt _0808FF50
	mov r0, sl
	adds r0, #0x20
	cmp r3, r0
	bge _0808FF50
	cmp r2, sb
	blt _0808FF50
	mov r0, sb
	adds r0, #0x20
	cmp r2, r0
	bge _0808FF50
	movs r4, #0
	subs r0, r5, #1
	cmp r0, #4
	bhi _0808FF2A
	lsls r0, r0, #2
	ldr r1, _0808FF08 @ =_0808FF0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808FF00: .4byte 0x00004038
_0808FF04: .4byte 0x030046A0
_0808FF08: .4byte _0808FF0C
_0808FF0C: @ jump table
	.4byte _0808FF20 @ case 0
	.4byte _0808FF24 @ case 1
	.4byte _0808FF28 @ case 2
	.4byte _0808FF28 @ case 3
	.4byte _0808FF28 @ case 4
_0808FF20:
	movs r4, #0xd
	b _0808FF2A
_0808FF24:
	movs r4, #0xf
	b _0808FF2A
_0808FF28:
	movs r4, #1
_0808FF2A:
	movs r0, #1
	adds r1, r3, #0
	bl FUN_0808a420
	adds r5, r0, #0
	ldrb r0, [r6]
	bl FUN_0808fe78
	cmp r0, #0
	beq _0808FF48
	ldr r2, _0808FF44 @ =0xFFFFE400
	adds r0, r2, #0
	b _0808FF4C
	.align 2, 0
_0808FF44: .4byte 0xFFFFE400
_0808FF48:
	ldr r1, _0808FF7C @ =0xFFFFE000
	adds r0, r1, #0
_0808FF4C:
	orrs r4, r0
	strh r4, [r5]
_0808FF50:
	adds r7, #1
_0808FF52:
	cmp r7, #0x1f
	bgt _0808FF6C
	ldr r0, _0808FF80 @ =0x00004034
	add r0, r8
	lsls r1, r7, #2
	ldr r0, [r0]
	adds r6, r0, r1
	ldrb r0, [r6]
	bl FUN_0808fe70
	adds r5, r0, #0
	cmp r5, #0
	bne _0808FEA0
_0808FF6C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FF7C: .4byte 0xFFFFE000
_0808FF80: .4byte 0x00004034
