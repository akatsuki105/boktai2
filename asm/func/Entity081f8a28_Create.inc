	push {r4, lr}
	ldr r0, _081F8A5C @ =0x03000208
	ldr r0, [r0]
	cmp r0, #0
	bne _081F8A6E
	ldr r1, _081F8A60 @ =0x0000095C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F8A6C
	ldr r1, _081F8A64 @ =Entity081f8a28_Update
	ldr r2, _081F8A68 @ =Entity081f8a28_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f8a28_Init
	cmp r0, #0
	bge _081F8A6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F8A6E
	.align 2, 0
_081F8A5C: .4byte 0x03000208
_081F8A60: .4byte 0x0000095C
_081F8A64: .4byte Entity081f8a28_Update
_081F8A68: .4byte Entity081f8a28_Destroy
_081F8A6C:
	adds r0, r4, #0
_081F8A6E:
	pop {r4}
	pop {r1}
	bx r1
