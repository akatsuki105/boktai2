	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0808E820 @ =0xFFFF0000
	ands r0, r5
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _0808E824 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
	adds r5, r0, #0
	orrs r5, r1
	ldr r0, _0808E828 @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _0808E82C @ =0x00004022
	adds r0, r7, r2
	ldrh r2, [r0]
	ldr r3, _0808E830 @ =0x0000401E
	adds r0, r7, r3
	ldrb r0, [r0]
	muls r0, r2, r0
	ldr r4, [r1]
	adds r4, r4, r0
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
	subs r4, r4, r1
	str r4, [sp, #0xc]
	mov sl, sp
	ldr r0, _0808E834 @ =0x00002164
	adds r4, r7, r0
	movs r2, #0x90
	lsls r2, r2, #5
	mov sb, r2
	movs r3, #3
	mov r8, r3
_0808E7BE:
	ldr r0, _0808E838 @ =0x00000F6C
	adds r2, r7, r0
	add r2, sb
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	str r5, [r4, #0x20]
	str r6, [r4, #0x24]
	mov r3, sl
	adds r3, #4
	mov sl, r3
	subs r3, #4
	ldm r3!, {r2}
	adds r2, #0x14
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0x60
	movs r3, #1
	bl MainSprite_SetPose
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0808E820 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	adds r4, #0x60
	movs r0, #0x60
	add sb, r0
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	mov r3, r8
	cmp r3, #0
	bge _0808E7BE
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E820: .4byte 0xFFFF0000
_0808E824: .4byte 0x0000FFFF
_0808E828: .4byte 0x030046A0
_0808E82C: .4byte 0x00004022
_0808E830: .4byte 0x0000401E
_0808E834: .4byte 0x00002164
_0808E838: .4byte 0x00000F6C
