	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081019e0
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08101BE4
	ldr r1, _08101C14 @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08101C04
_08101BE4:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _08101C18 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_08101C04:
	adds r0, r4, #0
	bl FUN_08101bb4
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08101C14: .4byte 0x000004BE
_08101C18: .4byte 0x0000062C
