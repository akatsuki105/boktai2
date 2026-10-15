	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081e2628
	adds r0, r4, #0
	bl FUN_081e27f0
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e3f0c
	adds r0, r4, #0
	bl FUN_081e4054
	ldr r1, _081E8550 @ =0x00001615
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081E8554 @ =0x00001610
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081E8558 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081e2e84
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, _081E855C @ =0x00001628
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, _081E8560 @ =0x00001626
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl LinkShopManager_SetOwner
	ldr r0, _081E8564 @ =FUN_081e3958
	ldr r1, _081E8568 @ =FUN_081e3cd4
	ldr r2, _081E856C @ =FUN_081e3cc0
	bl LinkShopManager_SetCallbacks
	adds r0, r4, #0
	bl FUN_081e3d78
	adds r0, r4, #0
	bl FUN_081e2b08
	ldr r0, _081E8570 @ =FUN_081e80ac
	movs r2, #0x14
	str r0, [r4, #0x18]
	ldr r0, _081E8574 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E8578 @ =0x00001616
	adds r4, r4, r1
	strb r2, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E8550: .4byte 0x00001615
_081E8554: .4byte 0x00001610
_081E8558: .4byte 0x00001617
_081E855C: .4byte 0x00001628
_081E8560: .4byte 0x00001626
_081E8564: .4byte FUN_081e3958
_081E8568: .4byte FUN_081e3cd4
_081E856C: .4byte FUN_081e3cc0
_081E8570: .4byte FUN_081e80ac
_081E8574: .4byte 0x00001614
_081E8578: .4byte 0x00001616
