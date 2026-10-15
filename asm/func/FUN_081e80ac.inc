	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E80D8 @ =0x00001614
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E80BE
	movs r0, #0
	strb r0, [r1]
_081E80BE:
	bl LinkShopManager_IsReady
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E80FC
	bl LinkShopManager_IsParent
	cmp r0, #0
	beq _081E80DC
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E80E2
	.align 2, 0
_081E80D8: .4byte 0x00001614
_081E80DC:
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E80E2:
	ldr r0, _081E8104 @ =FUN_081e8110
	movs r2, #2
	str r0, [r4, #0x18]
	ldr r0, _081E8108 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E810C @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_081e275c
_081E80FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E8104: .4byte FUN_081e8110
_081E8108: .4byte 0x00001614
_081E810C: .4byte 0x00001616
