	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b760
	adds r2, r0, #0
	cmp r2, #0
	bne _080945A8
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08092744
	b _080945E2
_080945A8:
	cmp r2, #1
	bne _080945E2
	ldr r0, _080945E8 @ =0x0000144C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl TextBox_Close
	ldr r0, _080945EC @ =0x00003AEE
	adds r4, r5, r0
	ldrb r2, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0x14
	bl FUN_08092300
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_08091e48
	adds r0, r5, #0
	bl FUN_0809223c
	ldr r1, _080945F0 @ =FUN_080945f4
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
_080945E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080945E8: .4byte 0x0000144C
_080945EC: .4byte 0x00003AEE
_080945F0: .4byte FUN_080945f4
