	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08229CAC @ =0x03000248
	ldr r0, [r0]
	cmp r0, #0
	bne _08229CBE
	movs r1, #0xf6
	lsls r1, r1, #4
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08229CBC
	ldr r1, _08229CB0 @ =0x00000F46
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _08229CB4 @ =Entity8AAB_Update
	ldr r2, _08229CB8 @ =Entity8AAB_Destroy
	adds r0, r4, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity8AAB_Init
	cmp r0, #0
	bge _08229CBC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08229CBE
	.align 2, 0
_08229CAC: .4byte 0x03000248
_08229CB0: .4byte 0x00000F46
_08229CB4: .4byte Entity8AAB_Update
_08229CB8: .4byte Entity8AAB_Destroy
_08229CBC:
	adds r0, r4, #0
_08229CBE:
	pop {r4, r5}
	pop {r1}
	bx r1
