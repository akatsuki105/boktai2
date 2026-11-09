	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	movs r1, #4
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081604EC
	ldr r1, _08160520 @ =0x000004BE
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08160518
_081604EC:
	adds r0, r4, #0
	bl Cockatrice_PreUpdate
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r3, _08160524 @ =0x0000062C
	adds r1, r4, r3
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Enemy_RunStateHandler
	adds r0, r4, #0
	bl Cockatrice_PostUpdate
_08160518:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08160520: .4byte 0x000004BE
_08160524: .4byte 0x0000062C
