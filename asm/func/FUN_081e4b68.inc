	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _081E4B88 @ =0x0000162C
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	bne _081E4B90
	bl Save_SwitchSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E4B90
	ldr r0, _081E4B8C @ =FUN_081e6388
	movs r2, #0x18
	b _081E4B94
	.align 2, 0
_081E4B88: .4byte 0x0000162C
_081E4B8C: .4byte FUN_081e6388
_081E4B90:
	ldr r0, _081E4BAC @ =FUN_081e6458
	movs r2, #0x19
_081E4B94:
	str r0, [r4, #0x18]
	ldr r0, _081E4BB0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4BB4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4BAC: .4byte FUN_081e6458
_081E4BB0: .4byte 0x00001614
_081E4BB4: .4byte 0x00001616
