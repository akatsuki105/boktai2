	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	bl FUN_081cb3a4
	ldr r1, _081CE698 @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081CE688
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _081CE69C @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Enemy_RunStateHandler
_081CE688:
	adds r0, r5, #0
	bl FUN_081cb3dc
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081CE698: .4byte 0x000004BE
_081CE69C: .4byte 0x0000062C
