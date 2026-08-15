	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _082415FA
	adds r4, r5, #0
	adds r4, #0x18
	b _082415F2
_082415EC:
	bl Script_GetValue
	stm r4!, {r0}
_082415F2:
	bl VM_GetPC
	cmp r0, #0
	bne _082415EC
_082415FA:
	ldr r0, _08241608 @ =0x03001704
	str r5, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08241608: .4byte 0x03001704
