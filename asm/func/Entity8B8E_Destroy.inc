	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081e44d0
	adds r0, r4, #0
	bl FUN_081e44b4
	adds r0, r4, #0
	bl FUN_081e4484
	bl LinkShopManager_IsFinished
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _081E84AC
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl Taiyo_Enable
	ldr r0, _081E84B4 @ =0x0300481C
	str r5, [r0]
	ldr r0, _081E84B8 @ =0x00001626
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E84AC
	movs r1, #0
	bl VM_ExecByID
_081E84AC:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E84B4: .4byte 0x0300481C
_081E84B8: .4byte 0x00001626
