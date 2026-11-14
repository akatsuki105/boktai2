	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _0808D634 @ =0x00000D98
	adds r2, r7, r0
	movs r0, #0xff
	strb r0, [r2]
	mov sl, r6
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808D6BC
	movs r5, #0
	ldr r0, _0808D638 @ =0x030046A0
	mov sb, r0
_0808D5FE:
	movs r1, #0
	mov ip, r1
	movs r3, #0
	movs r2, #1
	rsbs r2, r2, #0
	mov r8, r2
	mov r1, sb
	ldr r0, [r1]
	lsls r4, r5, #1
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0808D63C
	bl GetWeapon
	adds r3, r0, #0
	mov r1, sb
	ldr r0, [r1]
	adds r0, r4, r0
	adds r0, #0x60
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r8, r2
	b _0808D670
	.align 2, 0
_0808D634: .4byte 0x00000D98
_0808D638: .4byte 0x030046A0
_0808D63C:
	movs r2, #0
	ldr r0, _0808D654 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808D658
	mov r0, sl
	cmp r0, #0
	bne _0808D65E
	b _0808D662
	.align 2, 0
_0808D654: .4byte 0x030047A4
_0808D658:
	cmp r5, #3
	bne _0808D65E
	movs r2, #1
_0808D65E:
	cmp r2, #0
	beq _0808D66A
_0808D662:
	movs r3, #0
	movs r1, #1
	mov sl, r1
	mov ip, r1
_0808D66A:
	mov r2, ip
	cmp r2, #0
	beq _0808D69A
_0808D670:
	movs r0, #0x68
	muls r0, r6, r0
	ldr r1, _0808D6A4 @ =0x00000D9C
	adds r0, r0, r1
	adds r0, r7, r0
	strb r5, [r0]
	mov r2, r8
	strb r2, [r0, #1]
	str r3, [r0, #4]
	ldr r1, _0808D6A8 @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x58
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov sb, r1
	cmp r5, r0
	bne _0808D698
	ldr r1, _0808D6AC @ =0x00000D98
	adds r0, r7, r1
	strb r6, [r0]
_0808D698:
	adds r6, #1
_0808D69A:
	adds r5, #1
	cmp r5, #3
	ble _0808D5FE
	b _0808D6D2
	.align 2, 0
_0808D6A4: .4byte 0x00000D9C
_0808D6A8: .4byte 0x030046A0
_0808D6AC: .4byte 0x00000D98
_0808D6B0:
	ldr r3, _0808D6B8 @ =0x00000D98
	adds r0, r7, r3
	strb r2, [r0]
	b _0808D754
	.align 2, 0
_0808D6B8: .4byte 0x00000D98
_0808D6BC:
	ldr r1, _0808D764 @ =0x00000D9C
	adds r0, r7, r1
	movs r1, #3
	strb r1, [r0]
	strb r6, [r0, #1]
	movs r3, #0xff
	lsls r3, r3, #6
	adds r1, r7, r3
	str r1, [r0, #4]
	strb r6, [r2]
	movs r6, #1
_0808D6D2:
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r7, r1
	strb r6, [r0]
	ldr r4, _0808D768 @ =0x030047A4
	cmp r6, #3
	bgt _0808D704
	movs r2, #0xff
	movs r3, #0
	movs r0, #0x68
	muls r0, r6, r0
	ldr r1, _0808D764 @ =0x00000D9C
	adds r0, r0, r1
	adds r1, r0, r7
_0808D6EE:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r1, #1]
	orrs r0, r2
	strb r0, [r1, #1]
	str r3, [r1, #4]
	adds r1, #0x68
	adds r6, #1
	cmp r6, #3
	ble _0808D6EE
_0808D704:
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0808D754
	ldr r2, _0808D76C @ =0x00000D98
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808D754
	ldr r0, _0808D770 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #3
	strh r1, [r0]
	movs r2, #0
	movs r5, #0
	movs r3, #0xf4
	lsls r3, r3, #4
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D754
	adds r3, r0, #0
	ldr r0, _0808D764 @ =0x00000D9C
	adds r1, r7, r0
_0808D73E:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #3
	beq _0808D6B0
	cmp r0, #0
	blt _0808D74C
	adds r2, #1
_0808D74C:
	adds r1, #0x68
	adds r5, #1
	cmp r5, r3
	blt _0808D73E
_0808D754:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D764: .4byte 0x00000D9C
_0808D768: .4byte 0x030047A4
_0808D76C: .4byte 0x00000D98
_0808D770: .4byte 0x030046A0
