	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b760
	adds r2, r0, #0
	cmp r2, #0
	bne _080975A0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08096fa8
	b _080975EC
_080975A0:
	cmp r2, #1
	bne _080975EC
	ldr r0, _080975F4 @ =0x0000144C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080975F8 @ =0x00003AEE
	adds r4, r5, r1
	ldrb r2, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0x14
	bl FUN_08096cac
	ldrb r0, [r4]
	ldr r1, _080975FC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_0809673c
	adds r0, r5, #0
	bl FUN_08096b44
	ldr r1, _08097600 @ =FUN_08097604
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
_080975EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080975F4: .4byte 0x0000144C
_080975F8: .4byte 0x00003AEE
_080975FC: .4byte 0x030046A0
_08097600: .4byte FUN_08097604
