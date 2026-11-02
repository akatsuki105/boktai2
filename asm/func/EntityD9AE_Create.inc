	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08004654 @ =0x03000020
	ldr r0, [r0]
	cmp r0, #0
	bne _08004662
	movs r0, #8
	movs r1, #0x74
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08004660
	ldr r1, _08004658 @ =EntityD9AE_Update
	ldr r2, _0800465C @ =EntityD9AE_Destroy
	bl SetEntityRoutine
	movs r0, #0x6d
	movs r1, #8
	bl VM_GetNamedArgValue
	strh r0, [r4, #0x18]
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityD9AE_Init
	cmp r0, #0
	bge _08004660
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08004662
	.align 2, 0
_08004654: .4byte 0x03000020
_08004658: .4byte EntityD9AE_Update
_0800465C: .4byte EntityD9AE_Destroy
_08004660:
	adds r0, r4, #0
_08004662:
	pop {r4, r5}
	pop {r1}
	bx r1
