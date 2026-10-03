	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	adds r4, r0, #0
	mov sb, r1
	ldr r0, _08099634 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r6, #2
	rsbs r6, r6, #0
	ands r0, r6
	str r0, [r1]
	ldr r1, _08099638 @ =0x00001444
	adds r0, r4, r1
	movs r1, #0x60
	adds r1, r1, r4
	mov r8, r1
	movs r5, #0
	str r5, [sp]
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r0, _0809963C @ =0x000020AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	ldr r1, _08099640 @ =0x000020A4
	adds r6, r4, r1
	adds r0, r6, #0
	mov r1, r8
	movs r2, #0x42
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _08099644 @ =0x000020C4
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _08099648 @ =0x000002A5
	adds r0, r6, #0
	bl FUN_0808ba0c
	ldr r1, _0809964C @ =0x00004002
	adds r0, r4, r1
	mov r1, sb
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08098e48
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08099634: .4byte 0x0000144C
_08099638: .4byte 0x00001444
_0809963C: .4byte 0x000020AC
_08099640: .4byte 0x000020A4
_08099644: .4byte 0x000020C4
_08099648: .4byte 0x000002A5
_0809964C: .4byte 0x00004002
