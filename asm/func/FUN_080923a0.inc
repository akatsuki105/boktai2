	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _0809242C @ =0xFFFF0000
	movs r4, #0
	ands r5, r0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r0, r0, r6
	mov r8, r0
	ldr r0, [r0]
	ldr r1, _08092430 @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _08092434 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	ble _08092400
	ldr r1, _08092438 @ =0x000026A4
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xad
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _0809243C @ =0x000026AC
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08092440 @ =0x000026C4
	adds r0, r6, r1
	str r4, [r0]
	str r5, [r0, #4]
	movs r4, #0xd0
	lsls r4, r4, #0xc
	movs r7, #1
_08092400:
	mov r2, r8
	ldr r1, [r2]
	ldr r2, _08092444 @ =0x000004C7
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08092484
	subs r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08092448
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08092438 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xab
	b _080924A0
	.align 2, 0
_0809242C: .4byte 0xFFFF0000
_08092430: .4byte 0x0000038E
_08092434: .4byte 0x030046A0
_08092438: .4byte 0x000026A4
_0809243C: .4byte 0x000026AC
_08092440: .4byte 0x000026C4
_08092444: .4byte 0x000004C7
_08092448:
	cmp r0, #2
	bne _08092464
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _08092460 @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xaa
	b _080924A0
	.align 2, 0
_08092460: .4byte 0x000026A4
_08092464:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08092480 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xac
	movs r3, #1
	bl MainSprite_SetPose
	b _080924A6
	.align 2, 0
_08092480: .4byte 0x000026A4
_08092484:
	ldr r2, _080925B8 @ =0x0000043E
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080924DC
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080925BC @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xae
_080924A0:
	movs r3, #1
	bl MainSprite_SetPose
_080924A6:
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080925C0 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _080925C4 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r2, r4, #0
	asrs r0, r2, #0x10
	adds r0, #0xd
	lsls r0, r0, #0x10
	ldr r1, _080925C8 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
	adds r7, #1
_080924DC:
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r0, r0, r6
	mov r8, r0
	ldr r0, [r0]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08092540
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _080925BC @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xaf
	movs r3, #1
	bl MainSprite_SetPose
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080925C0 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _080925C4 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r2, r4, #0
	asrs r0, r2, #0x10
	adds r0, #0xd
	lsls r0, r0, #0x10
	ldr r1, _080925C8 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
	adds r7, #1
_08092540:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080925CC @ =0x0000043C
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809258C
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080925BC @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb0
	movs r3, #1
	bl MainSprite_SetPose
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080925C0 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _080925C4 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r7, #1
_0809258C:
	cmp r7, #3
	bgt _080925AC
	movs r2, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080925D0 @ =0x000026AC
	adds r0, r0, r1
	adds r1, r0, r6
_0809259E:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	adds r7, #1
	cmp r7, #3
	ble _0809259E
_080925AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080925B8: .4byte 0x0000043E
_080925BC: .4byte 0x000026A4
_080925C0: .4byte 0x00000F6C
_080925C4: .4byte 0x00000F84
_080925C8: .4byte 0x0000FFFF
_080925CC: .4byte 0x0000043C
_080925D0: .4byte 0x000026AC
