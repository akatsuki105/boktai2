	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	bl FUN_08165460
	ldr r1, _0816554C @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816553C
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _08165550 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Enemy_RunStateHandler
_0816553C:
	adds r0, r5, #0
	bl FUN_08165464
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0816554C: .4byte 0x000004BE
_08165550: .4byte 0x0000062C
