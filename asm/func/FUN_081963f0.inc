	push {lr}
	adds r1, r0, #0
	ldr r0, _08196414 @ =0x00000C64
	adds r2, r1, r0
	ldr r0, [r2]
	subs r0, #1
	str r0, [r2]
	cmp r0, #0
	bne _08196410
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r2]
	ldr r0, _08196418 @ =0x00000C44
	adds r1, r1, r0
	ldr r0, _0819641C @ =FUN_08196420
	str r0, [r1]
_08196410:
	pop {r0}
	bx r0
	.align 2, 0
_08196414: .4byte 0x00000C64
_08196418: .4byte 0x00000C44
_0819641C: .4byte FUN_08196420
