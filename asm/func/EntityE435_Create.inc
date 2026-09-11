	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08017B28 @ =0x03000070
	ldr r0, [r0]
	cmp r0, #0
	bne _08017B6A
	movs r0, #0x61
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08017B2C
	movs r1, #0x9d
	lsls r1, r1, #2
	movs r0, #0xb
	b _08017B32
	.align 2, 0
_08017B28: .4byte 0x03000070
_08017B2C:
	movs r1, #0x9d
	lsls r1, r1, #2
	movs r0, #9
_08017B32:
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08017B68
	ldr r1, _08017B60 @ =EntityE435_Update
	ldr r2, _08017B64 @ =EntityE435_Destroy
	adds r0, r4, #0
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl EntityE435_Init
	cmp r0, #0
	bge _08017B68
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08017B6A
	.align 2, 0
_08017B60: .4byte EntityE435_Update
_08017B64: .4byte EntityE435_Destroy
_08017B68:
	adds r0, r4, #0
_08017B6A:
	pop {r4, r5}
	pop {r1}
	bx r1
