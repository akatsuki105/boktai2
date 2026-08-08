	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	blt _08064C94
	adds r0, r4, #0
	bl FUN_0824347c
	adds r5, r0, #0
	cmp r4, #5
	bgt _08064C64
	adds r0, r6, #0
	movs r1, #2
	b _08064C6C
_08064C64:
	subs r0, r4, #6
	movs r1, #4
	lsls r1, r0
	adds r0, r6, #0
_08064C6C:
	bl FUN_08060ed8
	adds r1, r0, #0
	cmp r1, #0
	bne _08064C94
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _08064C98
	cmp r5, #0
	bne _08064C8C
	cmp r4, #1
	beq _08064C94
	b _08064CF8
_08064C8C:
	cmp r5, #1
	beq _08064CF8
	cmp r5, #2
	bne _08064CFE
_08064C94:
	movs r0, #0
	b _08064CFE
_08064C98:
	cmp r1, #1
	bne _08064CDC
	cmp r5, #0
	bne _08064CB6
	cmp r4, #0
	beq _08064C94
	cmp r4, #2
	beq _08064C94
	cmp r4, #3
	beq _08064C94
	cmp r4, #4
	beq _08064C94
	cmp r4, #5
	beq _08064C94
	b _08064CF8
_08064CB6:
	cmp r5, #1
	beq _08064C94
	cmp r5, #2
	bne _08064CFE
	cmp r4, #0xe
	bne _08064CF8
	ldr r0, _08064CD4 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08064CD8 @ =0x00000252
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bge _08064C94
	b _08064CF8
	.align 2, 0
_08064CD4: .4byte 0x030046A0
_08064CD8: .4byte 0x00000252
_08064CDC:
	cmp r1, #5
	beq _08064CF8
	cmp r1, #2
	bne _08064CEA
	cmp r4, #0xf
	beq _08064CF8
	b _08064C94
_08064CEA:
	cmp r1, #3
	bne _08064CF4
	cmp r4, #0x10
	beq _08064CF8
	b _08064C94
_08064CF4:
	cmp r4, #0xe
	bne _08064CFC
_08064CF8:
	movs r0, #1
	b _08064CFE
_08064CFC:
	movs r0, #0
_08064CFE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
