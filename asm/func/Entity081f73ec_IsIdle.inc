	push {lr}
	ldr r0, _081F745C @ =0x030001FC
	ldr r0, [r0]
	cmp r0, #0
	beq _081F7464
	ldr r1, _081F7460 @ =0x00000722
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F7464
	movs r0, #0
	b _081F7466
	.align 2, 0
_081F745C: .4byte 0x030001FC
_081F7460: .4byte 0x00000722
_081F7464:
	movs r0, #1
_081F7466:
	pop {r1}
	bx r1
	.align 2, 0
