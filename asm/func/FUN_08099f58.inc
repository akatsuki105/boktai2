	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08099c1c
	ldr r0, _0809A054 @ =0x00001CEC
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	mov sb, r2
	ands r0, r2
	str r0, [r1]
	ldr r1, _0809A058 @ =0x00001D04
	adds r0, r4, r1
	movs r6, #0
	strh r6, [r0]
	ldr r2, _0809A05C @ =0x00001D06
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r5, r4, r2
	ldr r0, _0809A060 @ =0x000002A5
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl MainSprite_SetPltt
	movs r1, #0x60
	adds r1, r1, r4
	mov sl, r1
	adds r0, r5, #0
	movs r2, #0x4f
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _0809A064 @ =0x00001D4C
	adds r1, r4, r2
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r1, _0809A068 @ =0x00001D64
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _0809A06C @ =0x00001D66
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r5, r4, r2
	adds r0, r5, #0
	mov r1, r8
	bl MainSprite_SetPltt
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x52
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _0809A070 @ =0x00001DAC
	adds r1, r4, r0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r1, _0809A074 @ =0x00001DC4
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _0809A078 @ =0x00001DC6
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r5, r4, r2
	adds r0, r5, #0
	mov r1, r8
	bl MainSprite_SetPltt
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _0809A07C @ =0x00001464
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _0809A080 @ =0x00001466
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r0, r4, r2
	str r6, [sp]
	mov r1, sl
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08099c64
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A054: .4byte 0x00001CEC
_0809A058: .4byte 0x00001D04
_0809A05C: .4byte 0x00001D06
_0809A060: .4byte 0x000002A5
_0809A064: .4byte 0x00001D4C
_0809A068: .4byte 0x00001D64
_0809A06C: .4byte 0x00001D66
_0809A070: .4byte 0x00001DAC
_0809A074: .4byte 0x00001DC4
_0809A078: .4byte 0x00001DC6
_0809A07C: .4byte 0x00001464
_0809A080: .4byte 0x00001466
