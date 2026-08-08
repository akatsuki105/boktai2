	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_080ef840
	ldr r0, _080ECFB4 @ =0x03002C60
	ldr r2, [r0]
	ldr r1, [r2, #4]
	movs r3, #0
	cmp r1, #0
	beq _080ECFAC
	movs r0, #0xc2
	lsls r0, r0, #1
	mov ip, r0
	movs r6, #0x80
	lsls r6, r6, #0xa
	ldr r5, _080ECFB8 @ =0x000001DF
_080ECF80:
	mov r7, ip
	adds r0, r1, r7
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	ble _080ECFA4
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r1, r7
	ldr r0, [r0]
	ands r0, r6
	cmp r0, #0
	bne _080ECFA4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _080ECFA4
	adds r3, #1
_080ECFA4:
	ldr r2, [r2]
	ldr r1, [r2, #4]
	cmp r1, #0
	bne _080ECF80
_080ECFAC:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080ECFB4: .4byte 0x03002C60
_080ECFB8: .4byte 0x000001DF
