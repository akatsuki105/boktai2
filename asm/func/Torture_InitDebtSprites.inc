	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C06C8 @ =0x0000CB05
	ldr r1, _080C06CC @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	movs r0, #0xde
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r2, r4, #0
	adds r0, r1, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenMainSpriteFile
	ldr r2, _080C06D0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _080C06D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r2, #0
	movs r6, #0xe6
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x28
	movs r3, #0x30
	bl MainSprite_Add
	ldr r2, _080C06D8 @ =0x000003D2
	adds r0, r7, r2
	ldr r2, _080C06DC @ =0x000002A7
	strh r2, [r0]
	movs r5, #0xf8
	lsls r5, r5, #2
	adds r3, r7, r5
	ldr r0, _080C06E0 @ =0x03003584
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r6, #0
	mov sl, r6
	adds r5, r1, #0
	movs r0, #0x60
	mov r8, r0
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r4, r7, r1
	mov sb, r2
_080C0670:
	movs r0, #1
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xde
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r2, #0x1e
	movs r3, #0x30
	bl MainSprite_Add
	mov r0, sb
	strh r0, [r4, #0x3a]
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r2, r7, r1
	add r2, r8
	ldr r0, _080C06E0 @ =0x03003584
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	movs r2, #0x60
	add r8, r2
	adds r4, #0x60
	adds r6, #1
	cmp r6, #3
	ble _080C0670
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C06C8: .4byte 0x0000CB05
_080C06CC: .4byte 0x0000B343
_080C06D0: .4byte 0xFFFF0000
_080C06D4: .4byte 0x0000FFFF
_080C06D8: .4byte 0x000003D2
_080C06DC: .4byte 0x000002A7
_080C06E0: .4byte 0x03003584
