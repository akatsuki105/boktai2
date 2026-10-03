	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _08099770 @ =0xFFFF0000
	mov sb, r0
	movs r4, #0
	ands r5, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r1, r1, r6
	mov r8, r1
	ldr r0, [r1]
	ldr r2, _08099774 @ =0x0000038E
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r1, _08099778 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _08099742
	ldr r2, _0809977C @ =0x000026A4
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb4
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _08099780 @ =0x000026AC
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08099784 @ =0x000026C4
	adds r0, r6, r1
	str r4, [r0]
	str r5, [r0, #4]
	movs r4, #0xc
	movs r7, #1
_08099742:
	mov r2, r8
	ldr r1, [r2]
	ldr r2, _08099788 @ =0x000004C7
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08099808
	subs r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809978C
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _0809977C @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb2
	b _080997A2
	.align 2, 0
_08099770: .4byte 0xFFFF0000
_08099774: .4byte 0x0000038E
_08099778: .4byte 0x030046A0
_0809977C: .4byte 0x000026A4
_08099780: .4byte 0x000026AC
_08099784: .4byte 0x000026C4
_08099788: .4byte 0x000004C7
_0809978C:
	cmp r0, #2
	bne _080997B0
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _080997AC @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb1
_080997A2:
	movs r3, #1
	bl MainSprite_SetPose
	b _080997C8
	.align 2, 0
_080997AC: .4byte 0x000026A4
_080997B0:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080997F8 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb3
	movs r3, #1
	bl MainSprite_SetPose
_080997C8:
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080997FC @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099800 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r1, r4, #0
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08099804 @ =0xFFFF0000
	b _08099858
	.align 2, 0
_080997F8: .4byte 0x000026A4
_080997FC: .4byte 0x00000F6C
_08099800: .4byte 0x00000F84
_08099804: .4byte 0xFFFF0000
_08099808:
	ldr r2, _0809994C @ =0x0000043E
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08099860
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08099950 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb5
	movs r3, #1
	bl MainSprite_SetPose
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08099954 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099958 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r1, r4, #0
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
_08099858:
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r7, #1
_08099860:
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
	beq _080998C4
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _08099950 @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb6
	movs r3, #1
	bl MainSprite_SetPose
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08099954 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099958 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r1, r4, #0
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0809995C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r7, #1
_080998C4:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08099960 @ =0x0000043C
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08099910
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08099950 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb7
	movs r3, #1
	bl MainSprite_SetPose
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08099954 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099958 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r7, #1
_08099910:
	cmp r7, #0
	bne _08099920
	movs r0, #0xa
	movs r1, #9
	movs r2, #6
	movs r3, #1
	bl FUN_0808b97c
_08099920:
	cmp r7, #3
	bgt _08099940
	movs r2, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08099964 @ =0x000026AC
	adds r0, r0, r1
	adds r1, r0, r6
_08099932:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	adds r7, #1
	cmp r7, #3
	ble _08099932
_08099940:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809994C: .4byte 0x0000043E
_08099950: .4byte 0x000026A4
_08099954: .4byte 0x00000F6C
_08099958: .4byte 0x00000F84
_0809995C: .4byte 0xFFFF0000
_08099960: .4byte 0x0000043C
_08099964: .4byte 0x000026AC
