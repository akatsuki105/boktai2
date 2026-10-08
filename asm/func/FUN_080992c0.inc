	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	adds r5, r0, #0
	cmp r5, #0
	bne _08099304
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _080992FC @ =0x00004002
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x14
	adds r0, r4, #0
	bl EntityCC28_ShowLineInstant
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _08099300 @ =FUN_08099008
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _080993B4
	.align 2, 0
_080992FC: .4byte 0x00004002
_08099300: .4byte FUN_08099008
_08099304:
	cmp r5, #1
	bne _080993B4
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08098e88
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080612bc
	adds r0, r4, #0
	bl FUN_08098af4
	adds r0, r4, #0
	bl FUN_08098d98
	adds r0, r4, #0
	movs r1, #5
	movs r2, #7
	bl FUN_0808b604
	movs r6, #1
	rsbs r6, r6, #0
	adds r0, r4, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0808c658
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08099384
	ldr r0, _08099378 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r0, _0809937C @ =0x000020AC
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	bl EntityCC28_ShowLineInstant
	ldr r1, _08099380 @ =FUN_08098f7c
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	b _080993B4
	.align 2, 0
_08099378: .4byte 0x0000144C
_0809937C: .4byte 0x000020AC
_08099380: .4byte FUN_08098f7c
_08099384:
	ldr r1, _080993BC @ =0x00004002
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x14
	adds r0, r4, #0
	bl EntityCC28_ShowLineInstant
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl EntityCC28_DrawHP
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl EntityCC28_DrawEne
	ldr r1, _080993C0 @ =FUN_08099008
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
_080993B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080993BC: .4byte 0x00004002
_080993C0: .4byte FUN_08099008
