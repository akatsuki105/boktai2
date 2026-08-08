	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080712B4 @ =0x00000A68
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080712B8 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	movs r3, #0
	mov sb, r3
	movs r2, #0
	mov r8, r2
	strh r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, _080712BC @ =0x00000A8C
	adds r6, r4, r1
	strb r0, [r6]
	adds r0, r4, #0
	bl FUN_0806f900
	adds r5, r0, #0
	ldr r2, _080712C0 @ =0x000009F4
	adds r0, r4, r2
	movs r1, #0x2d
	bl FUN_0822b20c
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r2, _080712C4 @ =0x00000A7C
	adds r1, r4, r2
	ldrh r2, [r1]
	mov r3, r8
	str r3, [sp]
	ldr r3, _080712C8 @ =0x00000A7E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #8
	bl FUN_082364f8
	ldrb r1, [r6]
	ldr r2, _080712CC @ =0x00000A52
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080712D0 @ =0x00000A8A
	adds r0, r4, r3
	mov r1, r8
	strh r1, [r0]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r4, r4, r2
	mov r3, sb
	strb r3, [r4]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080712B4: .4byte 0x00000A68
_080712B8: .4byte 0x00000A6A
_080712BC: .4byte 0x00000A8C
_080712C0: .4byte 0x000009F4
_080712C4: .4byte 0x00000A7C
_080712C8: .4byte 0x00000A7E
_080712CC: .4byte 0x00000A52
_080712D0: .4byte 0x00000A8A
