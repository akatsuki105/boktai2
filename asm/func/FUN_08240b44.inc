	push {r4, r5, r6, r7, lr}
	ldr r0, _08240B74 @ =0x03001700
	ldr r0, [r0]
	cmp r0, #0
	beq _08240B90
	movs r7, #4
	ldr r6, _08240B78 @ =0x0000FFFB
	adds r1, r0, #0
	adds r1, #0x20
	ldr r0, _08240B7C @ =0x0000FFFF
	adds r5, r0, #0
	movs r4, #7
_08240B5C:
	ldrh r2, [r1, #4]
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08240B80
	adds r0, r6, #0
	ands r0, r2
	strh r0, [r1, #4]
	b _08240B88
	.align 2, 0
_08240B74: .4byte 0x03001700
_08240B78: .4byte 0x0000FFFB
_08240B7C: .4byte 0x0000FFFF
_08240B80:
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	strh r3, [r1, #4]
_08240B88:
	adds r1, #0x10
	subs r4, #1
	cmp r4, #0
	bge _08240B5C
_08240B90:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
