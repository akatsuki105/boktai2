	push {lr}
	ldrb r1, [r0, #7]
	cmp r1, #1
	beq _0804962C
	cmp r1, #1
	bgt _0804961E
	cmp r1, #0
	beq _08049628
	b _08049638
_0804961E:
	cmp r1, #2
	beq _08049630
	cmp r1, #3
	beq _08049634
	b _08049638
_08049628:
	ldr r0, [r0, #0x1c]
	b _0804963A
_0804962C:
	ldr r0, [r0, #0x20]
	b _0804963A
_08049630:
	ldr r0, [r0, #0x24]
	b _0804963A
_08049634:
	ldr r0, [r0, #0x28]
	b _0804963A
_08049638:
	movs r0, #0
_0804963A:
	pop {r1}
	bx r1
	.align 2, 0
