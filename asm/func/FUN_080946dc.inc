	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08094724 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080946F0
	ldr r0, _08094728 @ =0x0000038A
	bl PlaySound_082406e0
_080946F0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _0809473C
	ldrh r0, [r4]
	movs r4, #0xc
	subs r4, r4, r0
	ldr r1, _0809472C @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08094730 @ =0x00003B68
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	ldr r1, _08094734 @ =0x00002124
	adds r0, r5, r1
	ldr r2, _08094738 @ =0x00003B70
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	b _0809476A
	.align 2, 0
_08094724: .4byte 0x000009EE
_08094728: .4byte 0x0000038A
_0809472C: .4byte 0x000020C4
_08094730: .4byte 0x00003B68
_08094734: .4byte 0x00002124
_08094738: .4byte 0x00003B70
_0809473C:
	ldr r0, _08094770 @ =0x000020AC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08094774 @ =0x0000210C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08094778 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0809477C @ =0x00003AEB
	adds r0, r5, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_0809200c
	adds r0, r5, #0
	bl FUN_08092744
_0809476A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094770: .4byte 0x000020AC
_08094774: .4byte 0x0000210C
_08094778: .4byte 0x00003AEE
_0809477C: .4byte 0x00003AEB
