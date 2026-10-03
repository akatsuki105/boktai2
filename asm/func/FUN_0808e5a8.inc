	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0808E5D4 @ =0x00004022
	adds r0, r7, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0808E5D8
	movs r2, #0xc0
	adds r2, r2, r7
	mov sl, r2
	movs r1, #0
	add r0, sp, #0xc
_0808E5CA:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0808E5CA
	b _0808E61A
	.align 2, 0
_0808E5D4: .4byte 0x00004022
_0808E5D8:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
	movs r0, #0xc0
	adds r0, r0, r7
	mov sl, r0
_0808E61A:
	mov sb, sp
	ldr r1, _0808E688 @ =0x00003784
	adds r4, r7, r1
	ldr r6, _0808E68C @ =0x00002820
	movs r5, #3
_0808E624:
	ldr r2, _0808E690 @ =0x00000F6C
	adds r1, r7, r2
	adds r1, r1, r6
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	mov r8, r2
	ands r0, r2
	str r0, [r1]
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sl
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808E624
	ldr r2, _0808E694 @ =0x0000390C
	adds r1, r7, r2
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r1, _0808E698 @ =0x00004022
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0808E69C @ =0x0000401E
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	cmp r4, #0
	bne _0808E6A0
	movs r1, #0
	add r0, sp, #0xc
_0808E67E:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0808E67E
	b _0808E6DC
	.align 2, 0
_0808E688: .4byte 0x00003784
_0808E68C: .4byte 0x00002820
_0808E690: .4byte 0x00000F6C
_0808E694: .4byte 0x0000390C
_0808E698: .4byte 0x00004022
_0808E69C: .4byte 0x0000401E
_0808E6A0:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
_0808E6DC:
	mov r8, sp
	ldr r0, _0808E72C @ =0x00003964
	adds r4, r7, r0
	movs r6, #0xa8
	lsls r6, r6, #6
	movs r5, #3
_0808E6E8:
	ldr r1, _0808E730 @ =0x00000F6C
	adds r2, r7, r1
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r0, #4
	mov r8, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sl
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808E6E8
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E72C: .4byte 0x00003964
_0808E730: .4byte 0x00000F6C
