	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081de02c
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DE0D4 @ =0x000002C5
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #4
	bl ClearMemory
	ldr r2, _081DE0D8 @ =0x00000173
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	bl Time_GetSpanOfTime
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DE0D4: .4byte 0x000002C5
_081DE0D8: .4byte 0x00000173
