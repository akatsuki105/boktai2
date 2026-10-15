	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081E7AAC @ =0x00001614
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E7A54
	ldr r1, _081E7AB0 @ =0x0000162A
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E7A54:
	ldr r0, _081E7AB0 @ =0x0000162A
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x24
	bne _081E7A76
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E7AB4 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081E7A76:
	ldrh r0, [r4]
	cmp r0, #0x3c
	bls _081E7AB8
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7ABC
	adds r0, r5, #0
	bl FUN_081e3cd4
	adds r0, r5, #0
	bl KillEntity
	b _081E7ABC
	.align 2, 0
_081E7AAC: .4byte 0x00001614
_081E7AB0: .4byte 0x0000162A
_081E7AB4: .4byte 0x0000FFFF
_081E7AB8:
	adds r0, #1
	strh r0, [r4]
_081E7ABC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
