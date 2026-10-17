	push {lr}
	adds r3, r0, #0
	ldr r1, _08085B4C @ =0x0000032A
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08085B72
	cmp r0, #1
	bgt _08085B50
	cmp r0, #0
	beq _08085B56
	b _08085BCA
	.align 2, 0
_08085B4C: .4byte 0x0000032A
_08085B50:
	cmp r0, #2
	beq _08085BAA
	b _08085BCA
_08085B56:
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r2, r3, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08085BC8
	lsls r1, r0, #5
	subs r1, r1, r0
	asrs r1, r1, #6
	strh r1, [r3, #0x22]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	b _08085BCA
_08085B72:
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0x3f
	bhi _08085B82
	adds r1, r0, #0
	b _08085B88
_08085B82:
	ldrh r0, [r1]
	movs r1, #0x80
	subs r1, r1, r0
_08085B88:
	lsls r0, r1, #5
	subs r0, r0, r1
	asrs r0, r0, #6
	strh r0, [r3, #0x22]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _08085BCA
	movs r0, #0
	strh r0, [r1]
	b _08085BCA
_08085BAA:
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r3, r1
	ldrh r0, [r2]
	cmp r0, #0x3f
	bhi _08085BC6
	lsls r1, r0, #5
	subs r1, r1, r0
	asrs r1, r1, #6
	strh r1, [r3, #0x22]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	b _08085BCA
_08085BC6:
	movs r0, #0x1f
_08085BC8:
	strh r0, [r3, #0x22]
_08085BCA:
	pop {r0}
	bx r0
	.align 2, 0
