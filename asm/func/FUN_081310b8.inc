	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0812f818
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _081310E8 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Enemy_RunStateHandler
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081310E8: .4byte 0x0000062C
