	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0x98
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809F198
	b _0809F2E4
_0809F198:
	ldr r5, _0809F218 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xef
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	ldr r2, _0809F21C @ =0x0000270F
	cmp r0, r2
	ble _0809F1AC
	str r2, [r1]
_0809F1AC:
	ldr r0, [r5]
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
	add r5, sp, #0x10
	mov r6, r8
	adds r6, #0x34
	mov r1, r8
	ldrh r0, [r1, #0x34]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F220
	asrs r0, r0, #8
	b _0809F226
	.align 2, 0
_0809F218: .4byte 0x030046A0
_0809F21C: .4byte 0x0000270F
_0809F220:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F226:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F238
	asrs r0, r0, #8
	b _0809F23E
_0809F238:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F23E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0809F252
	asrs r0, r0, #8
	b _0809F258
_0809F252:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F258:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0809F2E0 @ =0x030047C8
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
	mov r1, sp
	ldrh r0, [r1, #0x10]
	subs r0, #0x10
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r1, #2]
	subs r0, #0x2c
	strh r0, [r1, #2]
	movs r0, #0x60
	add r0, r8
	mov sl, r0
	mov r7, r8
	adds r7, #0xa0
	mov sb, sp
	mov r6, r8
	adds r6, #0x80
	mov r4, r8
	adds r4, #0x88
	movs r5, #3
_0809F29C:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	ldm r1!, {r2}
	adds r2, #0x1e
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r7]
	str r1, [r7, #4]
	mov r1, sp
	ldrh r0, [r1, #0x10]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	adds r7, #0x60
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F29C
	b _0809F2FA
	.align 2, 0
_0809F2E0: .4byte 0x030047C8
_0809F2E4:
	movs r2, #1
	mov r1, r8
	adds r1, #0x88
	movs r5, #3
_0809F2EC:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F2EC
_0809F2FA:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
