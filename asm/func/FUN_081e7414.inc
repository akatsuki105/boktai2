	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r1, _081E7444 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E742E
	b _081E75C2
_081E742E:
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r3, _081E7448 @ =0x00001610
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081E744C
	movs r0, #1
	b _081E744E
	.align 2, 0
_081E7444: .4byte 0x00001614
_081E7448: .4byte 0x00001610
_081E744C:
	movs r0, #0
_081E744E:
	adds r6, r0, #0
	cmp r6, #0
	beq _081E7456
	b _081E7596
_081E7456:
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r0, #0x14
	str r0, [sp]
	str r6, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl Video_FillBGRect
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #2
	bl Video_SetBGLayer
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0x81
	lsls r0, r0, #4
	adds r5, r7, r0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r4, _081E7618 @ =0x030046A0
	ldr r0, [r4]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xfa
	lsls r1, r1, #2
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r6, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r3, _081E761C @ =0x000015F0
	adds r3, r3, r7
	mov sl, r3
	ldr r1, [r3]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r1, _081E7620 @ =0x000015E2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_081e37a0
	adds r0, r7, #0
	bl FUN_081e36e8
	adds r0, r7, #0
	bl FUN_081e3714
	adds r0, r7, #0
	bl FUN_081e49a8
	ldr r2, _081E7624 @ =0x00001599
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _081E7628 @ =0x00001619
	adds r0, r7, r3
	strb r6, [r0]
	ldr r1, _081E762C @ =0x0000161B
	adds r0, r7, r1
	strb r6, [r0]
	adds r2, #0x87
	adds r1, r7, r2
	ldr r0, _081E7630 @ =0x0000FFFF
	strh r0, [r1]
	adds r3, #1
	adds r1, r7, r3
	movs r0, #0x11
	strb r0, [r1]
	ldr r1, _081E7634 @ =0x00001608
	adds r0, r7, r1
	ldr r0, [r0]
	subs r2, #0x90
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	bl FUN_08049e5c
	mov r3, sl
	ldr r0, [r3]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r0, _081E7638 @ =0x00001617
	adds r1, r7, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _081E763C @ =0x00001514
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081E7596:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r2, _081E7640 @ =0x0000162A
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _081E7644 @ =0x00001614
	adds r0, r7, r3
	strb r2, [r0]
	ldr r1, _081E7638 @ =0x00001617
	adds r0, r7, r1
	strb r2, [r0]
	adds r0, r7, #0
	bl FUN_081e2ee8
_081E75C2:
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa
	bne _081E7654
	movs r0, #0x81
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r3, _081E763C @ =0x00001514
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r3, #0x60
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E7648 @ =0x00001624
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081E764C @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r7, #0x18]
	ldr r3, _081E7644 @ =0x00001614
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _081E7650 @ =0x00001616
	adds r0, r7, r2
	strb r1, [r0]
	b _081E78B2
	.align 2, 0
_081E7618: .4byte 0x030046A0
_081E761C: .4byte 0x000015F0
_081E7620: .4byte 0x000015E2
_081E7624: .4byte 0x00001599
_081E7628: .4byte 0x00001619
_081E762C: .4byte 0x0000161B
_081E7630: .4byte 0x0000FFFF
_081E7634: .4byte 0x00001608
_081E7638: .4byte 0x00001617
_081E763C: .4byte 0x00001514
_081E7640: .4byte 0x0000162A
_081E7644: .4byte 0x00001614
_081E7648: .4byte 0x00001624
_081E764C: .4byte FUN_081e653c
_081E7650: .4byte 0x00001616
_081E7654:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _081E766C @ =0x00001610
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081E7670
	movs r0, #1
	b _081E7672
	.align 2, 0
_081E766C: .4byte 0x00001610
_081E7670:
	movs r0, #0
_081E7672:
	cmp r0, #0
	beq _081E76A8
	ldr r0, _081E7698 @ =FUN_081e6810
	movs r2, #0x15
	str r0, [r7, #0x18]
	ldr r0, _081E769C @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E76A0 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _081E76A4 @ =0xFFFFF7FF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081E78B2
	.align 2, 0
_081E7698: .4byte FUN_081e6810
_081E769C: .4byte 0x00001614
_081E76A0: .4byte 0x00001616
_081E76A4: .4byte 0xFFFFF7FF
_081E76A8:
	adds r0, r7, #0
	bl FUN_081e2ee8
	ldr r3, _081E76D0 @ =0x00000808
	adds r0, r7, r3
	ldr r2, _081E76D4 @ =0x00000AC8
	adds r1, r7, r2
	bl MainSprite_AdvanceAnim
	adds r0, r7, #0
	bl FUN_081e4a60
	ldr r3, _081E76D8 @ =0x0000162A
	adds r1, r7, r3
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _081E76DC
	adds r0, #1
	strh r0, [r1]
	b _081E78B2
	.align 2, 0
_081E76D0: .4byte 0x00000808
_081E76D4: .4byte 0x00000AC8
_081E76D8: .4byte 0x0000162A
_081E76DC:
	adds r0, r7, #0
	bl FUN_081e4ab8
	adds r2, r0, #0
	adds r0, r7, #0
	add r1, sp, #0x10
	bl FUN_081e468c
	adds r1, r0, #0
	ldr r0, _081E7738 @ =0x0000161A
	adds r4, r7, r0
	ldrb r2, [r4]
	cmp r1, r2
	beq _081E77B8
	strb r1, [r4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bne _081E7744
	ldr r3, _081E773C @ =0x00001608
	adds r0, r7, r3
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _081E7740 @ =0x00001514
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _081E77A0
	.align 2, 0
_081E7738: .4byte 0x0000161A
_081E773C: .4byte 0x00001608
_081E7740: .4byte 0x00001514
_081E7744:
	ldr r1, _081E77A8 @ =0x00001608
	adds r0, r7, r1
	ldr r0, [r0]
	bl TextPanel_Start
	ldrb r1, [r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r2, _081E77AC @ =0x00000BC4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E7770
	ldr r3, _081E77B0 @ =0x00001514
	adds r0, r7, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E7770:
	movs r0, #0x81
	lsls r0, r0, #4
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r3, _081E77B4 @ =0x00000828
	adds r2, r7, r3
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_081e2ee8
_081E77A0:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E78B2
	.align 2, 0
_081E77A8: .4byte 0x00001608
_081E77AC: .4byte 0x00000BC4
_081E77B0: .4byte 0x00001514
_081E77B4: .4byte 0x00000828
_081E77B8:
	ldr r0, _081E77EC @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r5, #1
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _081E77FC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bne _081E78B2
	ldr r0, _081E77F0 @ =FUN_081e6b5c
	movs r1, #7
	str r0, [r7, #0x18]
	ldr r2, _081E77F4 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _081E77F8 @ =0x00001616
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E78B2
	.align 2, 0
_081E77EC: .4byte 0x030044E0
_081E77F0: .4byte FUN_081e6b5c
_081E77F4: .4byte 0x00001614
_081E77F8: .4byte 0x00001616
_081E77FC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E7874
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_081e4c64
	ldr r0, _081E785C @ =0x00001618
	adds r1, r7, r0
	movs r0, #0xa
	strb r0, [r1]
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r3, _081E7860 @ =0x00001514
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, _081E7864 @ =0x000014B4
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r2, #0xde
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r3, _081E7868 @ =0x00001624
	adds r0, r7, r3
	strb r5, [r0]
	ldr r0, _081E786C @ =FUN_081e5d14
	movs r1, #0x10
	str r0, [r7, #0x18]
	ldr r2, _081E7870 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	subs r3, #0xe
	adds r0, r7, r3
	strb r1, [r0]
	b _081E78B2
	.align 2, 0
_081E785C: .4byte 0x00001618
_081E7860: .4byte 0x00001514
_081E7864: .4byte 0x000014B4
_081E7868: .4byte 0x00001624
_081E786C: .4byte FUN_081e5d14
_081E7870: .4byte 0x00001614
_081E7874:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081E78B2
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	str r4, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0x19
	movs r1, #0x10
	movs r2, #5
	movs r3, #1
	bl FUN_081e4644
	ldr r0, _081E78C4 @ =FUN_081e564c
	movs r1, #0xb
	str r0, [r7, #0x18]
	ldr r2, _081E78C8 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _081E78CC @ =0x00001616
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E78B2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E78C4: .4byte FUN_081e564c
_081E78C8: .4byte 0x00001614
_081E78CC: .4byte 0x00001616
