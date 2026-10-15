	push {r4, r5, lr}
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
	adds r0, r4, #0
	bl FUN_081e3ce8
	adds r0, r4, #0
	bl FUN_081e32d8
	adds r0, r4, #0
	bl FUN_081e3444
	ldr r1, [r4, #0x1c]
	movs r0, #3
	movs r2, #1
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl LinkShopManager_IsParent
	cmp r0, #0
	beq _081E4E60
	ldr r0, _081E4E54 @ =FUN_081e7db4
	str r0, [r4, #0x18]
	ldr r0, _081E4E58 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4E5C @ =0x00001616
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_081e2d98
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E4E78
	.align 2, 0
_081E4E54: .4byte FUN_081e7db4
_081E4E58: .4byte 0x00001614
_081E4E5C: .4byte 0x00001616
_081E4E60:
	ldr r0, _081E4EC0 @ =FUN_081e7fd0
	movs r1, #1
	str r0, [r4, #0x18]
	ldr r2, _081E4EC4 @ =0x00001614
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E4E78:
	ldr r0, _081E4EC8 @ =0x00001615
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _081E4ECC @ =0x00001610
	adds r1, r4, r2
	movs r0, #0x3e
	str r0, [r1]
	ldr r1, _081E4ED0 @ =0x000015BC
	adds r0, r4, r1
	movs r1, #0x34
	bl ClearMemory
	ldr r2, _081E4ED4 @ =0x00000E04
	adds r0, r4, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r1, _081E4ED8 @ =0x00000E28
	adds r0, r4, r1
	movs r1, #0x24
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e4388
	adds r0, r4, #0
	bl FUN_081e49a8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4EC0: .4byte FUN_081e7fd0
_081E4EC4: .4byte 0x00001614
_081E4EC8: .4byte 0x00001615
_081E4ECC: .4byte 0x00001610
_081E4ED0: .4byte 0x000015BC
_081E4ED4: .4byte 0x00000E04
_081E4ED8: .4byte 0x00000E28
