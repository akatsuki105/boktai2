	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3dec
	ldr r1, _081E4D64 @ =0x00000BB4
	adds r0, r4, r1
	movs r1, #0x10
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3594
	ldr r1, [r4, #0x1c]
	movs r0, #3
	movs r2, #1
	bl Video_SetBGLayer
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl LinkShopManager_IsParent
	cmp r0, #0
	beq _081E4D68
	adds r0, r4, #0
	bl FUN_081e2d98
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E4D6E
	.align 2, 0
_081E4D64: .4byte 0x00000BB4
_081E4D68:
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E4D6E:
	ldr r2, _081E4DC4 @ =0x00001615
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	subs r2, #5
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _081E4DC8 @ =0x000015BC
	adds r0, r4, r1
	movs r1, #0x34
	bl ClearMemory
	ldr r2, _081E4DCC @ =0x00000E04
	adds r0, r4, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r1, _081E4DD0 @ =0x00000E28
	adds r0, r4, r1
	movs r1, #0x24
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e41e4
	ldr r0, _081E4DD4 @ =FUN_081e8110
	movs r2, #2
	str r0, [r4, #0x18]
	ldr r0, _081E4DD8 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4DDC @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4DC4: .4byte 0x00001615
_081E4DC8: .4byte 0x000015BC
_081E4DCC: .4byte 0x00000E04
_081E4DD0: .4byte 0x00000E28
_081E4DD4: .4byte FUN_081e8110
_081E4DD8: .4byte 0x00001614
_081E4DDC: .4byte 0x00001616
