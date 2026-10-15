	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _081E4C00 @ =0x0000162C
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	beq _081E4C10
	ldr r0, _081E4C04 @ =FUN_081e64cc
	movs r2, #0x1c
	str r0, [r4, #0x18]
	ldr r0, _081E4C08 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4C0C @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	b _081E4C2C
	.align 2, 0
_081E4C00: .4byte 0x0000162C
_081E4C04: .4byte FUN_081e64cc
_081E4C08: .4byte 0x00001614
_081E4C0C: .4byte 0x00001616
_081E4C10:
	adds r0, r4, #0
	bl FUN_081e5290
	adds r0, r4, #0
	bl LinkShopManager_SetOwner
	ldr r0, _081E4C34 @ =FUN_081e3958
	ldr r1, _081E4C38 @ =FUN_081e3cd4
	ldr r2, _081E4C3C @ =FUN_081e3cc0
	bl LinkShopManager_SetCallbacks
	adds r0, r4, #0
	bl FUN_081e4d04
_081E4C2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4C34: .4byte FUN_081e3958
_081E4C38: .4byte FUN_081e3cd4
_081E4C3C: .4byte FUN_081e3cc0
