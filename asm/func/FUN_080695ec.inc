	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08069606
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
_08069606:
	ldr r1, _08069618 @ =0x00000A98
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069618: .4byte 0x00000A98
